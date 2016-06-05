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
        rospy.loginfo(i)
        # Toplam hareket derecesi
        degisecek_derece = present_motor_data[i] - new_motor_data[i]
        # Her adimda kac derece hareket edecek
        float_derece = float(degisecek_derece) / adim_sayisi
        tek_adim.append(float_derece)
        # rospy.loginfo("Motor No: "+str(i)+" Pre: "+str(present_motor_data[i])+" Goal: "+str(new_motor_data[i])+ " Adim: "+str(float_derece) )

    for i in range(1, adim_sayisi+1):
        # Her bir adimda motorlarin gitmesi gereken pozisyon
        goal_motor_pos = IntArray() # Tum motorlarin goal pos lari

        for a in range(0,20):
            # Motor icin gitmesi gereken adimi mevcut posun ustune koy
            new_pos = float(present_motor_data[a] - (tek_adim[a] * i))
            goal_motor_pos.deger.append(int(new_pos))

        # Motora veriyi yolla
        pub_motor_array.publish(goal_motor_pos)
        rate.sleep()



def pos_calculate_kol(present_motor_data, new_motor_data, adim_sayisi):
    global pub_sync, pub_motor_array, pub_motor_single, rate
    # 6 Motorun Ayri Ayri Hesaplamalari

    tek_adim = [] # Her motorun bir dongude donecegi derece

    for i in range(0,6):
        rospy.loginfo(i)
        # Toplam hareket derecesi
        degisecek_derece = present_motor_data[i] - new_motor_data[i]
        # Her adimda kac derece hareket edecek
        float_derece = float(degisecek_derece) / adim_sayisi
        tek_adim.append(float_derece)
        # rospy.loginfo("Motor No: "+str(i)+" Pre: "+str(present_motor_data[i])+" Goal: "+str(new_motor_data[i])+ " Adim: "+str(float_derece) )

    for i in range(1, adim_sayisi+1):
        # Her bir adimda motorlarin gitmesi gereken pozisyon
        goal_motor_pos = IntArray() # Tum motorlarin goal pos lari

        for a in range(0,6):
            # Motor icin gitmesi gereken adimi mevcut posun ustune koy
            new_pos = float(present_motor_data[a] - (tek_adim[a] * i))
            
            # Motora veriyi yolla
            data = MotorOut()
            data.id = int(a+1)
            data.pos = int(new_pos)
            data.torque = -1
            
            pub_motor_single.publish(data)
            rate.sleep()



def pub_array_data(pos):
    global pub_motor_array, rate
    send_data = IntArray()

    for i in pos:
        # Motora veriyi yolla
        send_data.deger.append(int(i))

    rospy.loginfo("Published Array Data")
    
    pub_motor_array.publish(send_data)
    rate.sleep()



def pub_single_data(pos):
    global pub_motor_single, rate

    for i in pos:
        # Motora veriyi yolla
        data = MotorOut()

        data.id = (int(pos.index(i))+1)
        data.pos = int(i)
        data.torque = -1

        pub_motor_single.publish(data)
        rate.sleep()

    rospy.loginfo("Published Single Data")



# Motion Values
def values():
    global pos_oturma, pos_ayakta_durma

    pos_oturma = [544, 543, 445, 573, 544, 449, 512, 512, 485, 511, 355, 370, 84, 95, 188, 192, 495, 502, 514, 513]
    pos_ayakta_durma = [544, 543, 445, 573, 544, 449, 512, 512, 505, 525, 410, 410, 420, 420, 410, 410, 512, 512, 512, 512]






# Arduino Data Control
def control(data, value):
    global pub_sync, rate
    sync_data = DataControl()
    sync_data.data = data
    sync_data.value = [value]
    pub_sync.publish(sync_data)
    print "Published Data Control in Motion Control"
    rate.sleep()

def control_close_all():
    global pub_sync, rate
    sync_data = DataControl()
    sync_data.data = "motor"
    sync_data.value = [0]
    pub_sync.publish(sync_data)
    rate.sleep()
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
    print "Published Data Control in Motion Control"








# Main Service
def service_motion_command(req):
    global pub_sync, pub_motor_array, pub_motor_single, rate, head_access, now_pos, pos_oturma, pos_ayakta_durma

    komut = req.data
    
    if komut[:4] == "head":
        head_access = int(komut[5:])
        rospy.loginfo("Head Access Opened: "+ str(komut[5:]))
        
    elif komut == "add":
        # Mevcut motor pozisyonlarini kaydet
        rospy.loginfo(now_pos)

    elif komut == "play":
        # Mevcut motor pozisyonlarini kaydet
        goal_pos = pos_ayakta_durma
        pos_calculate(now_pos, goal_pos, 400)

    elif komut == "array":
        # Mevcut motor pozisyonlarini kaydet
        pub_array_data(pos_ayakta_durma)

    elif komut == "single":
        # Mevcut motor pozisyonlarini kaydet
        pub_single_data(pos_ayakta_durma)

    elif komut == "git":
        rospy.loginfo("git")
        control("motor",0)
        yeni = [219, 820, 701, 372, 381, 629]
        pos_calculate_kol(now_pos, yeni, 50)
        control("motor",1)

    elif komut == "gel":
        rospy.loginfo("gel")
        control("motor",0)
        yeni = [682, 326, 412, 564, 695, 287]
        pos_calculate_kol(now_pos, yeni, 50)
        control("motor",1)

    elif komut == "normal":
        control("motor",0)
        yeni = [513, 513, 459, 525, 562, 478]
        pos_calculate_kol(now_pos, yeni, 50)
        control("motor",1)

    elif komut == "otur":
        # Mevcut motor pozisyonlarini kaydet
        pub_single_data(pos_oturma)

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


# Tork Service
def service_motion_torque(req):
    global pub_sync, pub_motor_array, pub_motor_single, rate

    komut = req.data
    
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




# Subscriber


def callbackHead(data):
    global head_access

    head_x = data.deger[0]
    head_y = data.deger[1]

    if head_access == 0:
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
    global now_pos

    now_pos = []
    for i in range(0,20):
        now_pos.append(data.pos[i])






def main():

    global pub_sync, pub_motor_array, pub_motor_single, rate, head_access

    pub_sync = rospy.Publisher('arduino_data_sync', DataControl, queue_size=10) # Data Control
    pub_motor_array = rospy.Publisher('motor_out_array', IntArray, queue_size=10) # Motor Control Array 
    pub_motor_single = rospy.Publisher('motor_out_single', MotorOut, queue_size=10) # Motor Control Single

    rospy.Subscriber("motor_incoming_data", MotorInArray, callbackMotor) # Motor Incoming
    rospy.Subscriber("motor_head_position", IntArray, callbackHead) # Head Position

    rospy.Subscriber('service_motion_command', String, service_motion_command) # Sistem Komutlari
    rospy.Subscriber('service_motion_torque', String, service_motion_torque) # Motor Tork Komutlari
    
    pub_tts = rospy.Publisher('/service_tts', String, queue_size=10)

    values()
    head_access = 0 # Default Value

    rospy.init_node('motion_control_server', anonymous=True)
    rate = rospy.Rate(80)

    rospy.loginfo("READY: Motion Control Server")

    data = String()
    data.data = "add:Hareket sistemi hazIr"
    pub_tts.publish(data)

    rospy.spin()



if __name__ == '__main__':
    try:
        main()
    except rospy.ROSInterruptException:
        pass
