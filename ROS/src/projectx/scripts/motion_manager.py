#!/usr/bin/python

import rospy
import thread
import subprocess
import os
import time
from projectx.msg import *
from projectx.srv import *
from std_msgs.msg import *





## ZAMANA GORE MOTOR POS HESAPLAMA VE GONDERME
def pos_calculate(present_motor_data, new_motor_data, adim_sayisi):
    global pub_sync, pub_motor_array, pub_motor_single, rate
    # 20 Motorun Ayri Ayri Hesaplamalari

    tek_adim = [] # Her motorun bir dongude donecegi derece

    for i in range(0,20):
        # Toplam hareket derecesi
        degisecek_derece = new_motor_data[i] - present_motor_data[i]
        # Her adimda kac derece hareket edecek
        tek_adim.append(degisecek_derece / adim_sayisi)

    for i in range(0, adim_sayisi):
        # Her bir adimda motorlarin gitmesi gereken pozisyon
        goal_motor_pos = IntArray() # Tum motorlarin goal pos lari

        for a in range(0,20):
            # Motor icin gitmesi gereken adimi mevcut posun ustune koy
            new_pos = present_motor_data[a] + tek_adim[a]
            
            # Mevcut pozisyonlarini guncelle
            present_motor_data[a] = new_pos
            
            # Motora veriyi yolla
            data = MotorOut()
            data.id = int(int(a)+1)
            data.pos = int(new_pos)
            data.torque = -1

            pub_motor_single.publish(data)
            rate.sleep()




def pub_single_data(pos):
    global pub_motor_array, rate
    send_data = IntArray()

    for i in pos:
        # Motora veriyi yolla
        send_data.deger.append(int(i))

    rospy.loginfo("Published Single Data")
    
    pub_motor_array.publish(send_data)
    rate.sleep()




# Motion Values
def values():
    global pos_oturma, pos_ayakta_durma

    pos_oturma = [516, 538, 495, 412, 547, 447, 561, 498, 511, 500, 526, 356, 370, 80, 87, 192, 195, 509, 515, 512]
    pos_ayakta_durma = [512, 512, 400, 600, 512, 512, 512, 512, 480, 520, 400, 400, 440, 440, 430, 430, 512, 512, 512, 512]



# Arduino Data Control
def control(data):
    global pub_sync, rate
    sync_data = DataControl()
    sync_data.data = "motor"
    sync_data.value = [data]
    pub_sync.publish(sync_data)
    print "Published Data Control in Motor Playback Server"
    rate.sleep()

def control_close_all():
    global pub_sync, rate
    sync_data = DataControl()
    sync_data.data = "gyro"
    sync_data.value = [0]
    pub_sync.publish(sync_data)
    rate.sleep()
    sync_data = DataControl()
    sync_data.data = "sensor"
    sync_data.value = [0]
    pub_sync.publish(sync_data)
    rate.sleep()
    print "Published Data Control in Motor Playback Server"








# Main Service
def service_motion_command(req):
    global pub_sync, pub_motor_array, pub_motor_single, rate, head_access, motor_data, now_pos, pos_oturma, pos_ayakta_durma

    komut = req.in_data
    
    if komut[:4] == "head":
        head_access = int(komut[5:])
        rospy.loginfo("Head Access Opened: "+ str(komut[5:]))
        
    elif komut == "add":
        # Mevcut motor pozisyonlarini kaydet
        now_pos = motor_data
        rospy.loginfo(motor_data)

    elif komut == "play":
        # Mevcut motor pozisyonlarini kaydet
        goal_pos = pos_ayakta_durma
        pos_calculate(now_pos, goal_pos, 400)

    elif komut == "single":
        # Mevcut motor pozisyonlarini kaydet
        pub_single_data(pos_ayakta_durma)

    elif komut[:3] == "set":
        motor_id = int(komut[4:6])
        motor_pos = int(komut[7:])
        
        data = MotorOut()
        data.id = int(motor_id)
        data.pos = int(motor_pos)
        data.torque = -1

        rospy.loginfo("Motion Manager - WRITE POS: "+str(motor_id))

        pub_motor_single.publish(data)
        rate.sleep()


    return_data = "OK" # Simdilik

    res = MotorBoostResponse()
    res.out_data = return_data
    return res


# Tork Service
def service_motion_torque(req):
    global pub_sync, pub_motor_array, pub_motor_single, rate

    komut = req.in_data
    
    if komut[:2] == "on":
        motor_id = int(komut[3:])
        
        data = MotorOut()
        data.id = int(motor_id)
        data.pos = -1
        data.torque = 1

        rospy.loginfo("Motion Manager - WRITE TORQUE: "+str(motor_id)+" - ON")

        pub_motor_single.publish(data)
        rate.sleep()

    elif komut[:3] == "off":
        motor_id = int(komut[4:])
        
        data = MotorOut()
        data.id = int(motor_id)
        data.pos = -1
        data.torque = 0

        rospy.loginfo("Motion Manager - WRITE TORQUE: "+str(motor_id)+" - OFF")

        pub_motor_single.publish(data)
        rate.sleep()



    # ALL
    
    elif komut[:5] == "allon":
        
        for i in range(1,21):
            data = MotorOut()
            data.id = int(i)
            data.pos = -1
            data.torque = 1

            rospy.loginfo("Motion Manager - WRITE TORQUE: "+str(i)+" - ON")

            pub_motor_single.publish(data)
            rate.sleep()


    elif komut[:6] == "alloff":
        
        for i in range(1,21):
            data = MotorOut()
            data.id = int(i)
            data.pos = -1
            data.torque = 0

            rospy.loginfo("Motion Manager - WRITE TORQUE: "+str(i)+" - OFF")

            pub_motor_single.publish(data)
            rate.sleep()


    # LIST

    elif komut[:6] == "liston":
        list_name = str(komut[7:])

        motor_ids = []

        if str(list_name) == "solbacak":
            motor_ids = [7,9,11,13,15,17]

        elif str(list_name) == "sagbacak":
            motor_ids = [8,10,12,14,16,18]

        elif str(list_name) == "sagkol":
            motor_ids = [2,4,6]

        elif str(list_name) == "solkol":
            motor_ids = [1,3,5]

        elif str(list_name) == "kafa":
            motor_ids = [19,20]
        

        for i in motor_ids:
            data = MotorOut()
            data.id = int(i)
            data.pos = -1
            data.torque = 1
            
            rospy.loginfo("Motion Manager - WRITE TORQUE: "+str(i)+" - ON")
            
            pub_motor_single.publish(data)
            rate.sleep()



    elif komut[:7] == "listoff":
        list_name = str(komut[8:])

        motor_ids = []

        if str(list_name) == "solbacak":
            motor_ids = [7,9,11,13,15,17]
            
        elif str(list_name) == "sagbacak":
            motor_ids = [8,10,12,14,16,18]
            
        elif str(list_name) == "sagkol":
            motor_ids = [2,4,6]
            
        elif str(list_name) == "solkol":
            motor_ids = [1,3,5]
            
        elif str(list_name) == "kafa":
            motor_ids = [19,20]
        

        for i in motor_ids:
            data = MotorOut()
            data.id = int(i)
            data.pos = -1
            data.torque = 0
            
            rospy.loginfo("Motion Manager - WRITE TORQUE: "+str(i)+" - OFF")
            
            pub_motor_single.publish(data)
            rate.sleep()


    return_data = "OK" # Simdilik

    res = MotorBoostResponse()
    res.out_data = return_data
    return res




# Subscriber


def callbackHead(data):
    global head_access

    head_x = data.deger[0]
    head_y = data.deger[1]

    if head_access == 1:
        data = MotorOut()
        data.id = 19
        data.pos = head_x
        data.torque = -1
        
        pub_motor_single.publish(data)
        rate.sleep()

        data = MotorOut()
        data.id = 20
        data.pos = head_y
        data.torque = -1
        
        rospy.loginfo("Motion Manager - WRITE HEAD")
        
        pub_motor_single.publish(data)
        rate.sleep()


def callbackMotor(data):
    global motor_data, now_pos
    # rospy.loginfo(data)
    motor_data = data

    now_pos = []
    for i in range(0,20):
        now_pos.append(motor_data.pos[i])






def main():

    global pub_sync, pub_motor_array, pub_motor_single, rate, head_access

    pub_sync = rospy.Publisher('arduino_data_sync', DataControl, queue_size=10) # Data Control
    pub_motor_array = rospy.Publisher('motor_out_array', IntArray, queue_size=10) # Motor Control Array 
    pub_motor_single = rospy.Publisher('motor_out_single', MotorOut, queue_size=10) # Motor Control Single

    rospy.Subscriber("motor_incoming_data", MotorInArray, callbackMotor) # Motor Incoming
    rospy.Subscriber("motor_head_position", IntArray, callbackHead) # Head Position

    rospy.Service('service_motion_command', MotorBoost, service_motion_command) # Sistem Komutlari
    rospy.Service('service_motion_torque', MotorBoost, service_motion_torque) # Motor Tork Komutlari
    
    values()
    head_access = 0 # Default Value

    rospy.init_node('motion_control_server', anonymous=True)
    rate = rospy.Rate(20)

    rospy.loginfo("READY: Motion Control Server")

    rospy.spin()



if __name__ == '__main__':
    try:
        main()
    except rospy.ROSInterruptException:
        pass
