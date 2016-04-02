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
        degisecek_derece = new_motor_data[i] - present_motor_data.pos[i]
        # Her adimda kac derece hareket edecek
        tek_adim.append(degisecek_derece / adim_sayisi)

    for i in range(0, adim_sayisi):
        # Her bir adimda motorlarin gitmesi gereken pozisyon
        goal_motor_pos = IntArray() # Tum motorlarin goal pos lari

        for a in range(1,21):
            # Motor icin gitmesi gereken adimi mevcut posun ustune koy
            new_pos = pre_motor_data[a] + tek_adim[a]
            # Motorlara gidecek listeye ekle
            goal_motor_pos.append(new_pos)
            # Mevcut pozisyonlarini guncelle
            present_motor_data.pos[a] = new_pos

        # Her bir adimda goal poslari motorlara gonder
        rospy.loginfo("Motor Playback - Goal Pos Pub: "+ goal_motor_pos)
        pub_motor_single.publish(goal_motor_pos)
        rate.sleep()




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



# Node Service
def service_motion_command(req):
    global pub_sync, pub_motor_array, pub_motor_single, rate, head_access

    komut = req.in_data
    
    if komut[:4] == "head":
        head_access = int(komut[5:])
        rospy.loginfo("Head Access Opened: "+ str(komut[5:]))
        
    elif komut == "manual":
        control(1)


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
    global motor_data
    # rospy.loginfo(data)
    motor_data = data


def main():

    global pub_sync, pub_motor_array, pub_motor_single, rate, head_access

    pub_sync = rospy.Publisher('arduino_data_sync', DataControl, queue_size=10) # Data Control
    pub_motor_array = rospy.Publisher('motor_out_array', IntArray, queue_size=10) # Motor Control Array 
    pub_motor_single = rospy.Publisher('motor_out_single', MotorOut, queue_size=10) # Motor Control Single

    rospy.Subscriber("motor_incoming_data", MotorInArray, callbackMotor) # Motor Incoming
    rospy.Subscriber("motor_head_position", IntArray, callbackHead) # Head Position

    rospy.Service('service_motion_command', MotorBoost, service_motion_command) # Sistem Komutlari
    rospy.Service('service_motion_torque', MotorBoost, service_motion_torque) # Motor Tork Komutlari
    
    head_access = 0

    rospy.init_node('motion_control_server', anonymous=True)
    rate = rospy.Rate(100)

    rospy.loginfo("READY: Motion Control Server")

    rospy.spin()



if __name__ == '__main__':
    try:
        main()
    except rospy.ROSInterruptException:
        pass
