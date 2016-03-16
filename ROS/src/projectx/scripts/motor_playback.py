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
        pub_motor.publish(goal_motor_pos)
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




# Node Service
def service_motor(req):
    global process, pub_motor, rate, played
    komut = req.in_data

    played = 0
    
    if komut == "play":

        control(1)
        time.sleep(1)

        process = start()
        time.sleep(2)

        control(0)
        time.sleep(1)

        motor()
        rospy.loginfo("FILE READ - PLAY")

    elif komut == "manual":
        control(1)

    elif komut == "start":
        process = start()
        time.sleep(5)

        thread_single(process, "exit")
        rospy.loginfo("RME: EXIT")

    elif komut == "file":
        control(0)
        time.sleep(1)
        motor()
        rospy.loginfo("FILE READ - PLAY")

        time.sleep(1)
        control(1)
        os.system("sudo rm $HOME/Motor_Test.txt")

    elif komut == "exit":
        thread_single(process, "exit")
        rospy.loginfo("RME: EXIT")


    return_data = "OK" # Simdilik

    res = MotorBoostResponse()
    res.out_data = return_data
    return res


def callbackMotor(data):
    global motor_data
    # rospy.loginfo(data)
    motor_data = data


def main():

    pub_sync = rospy.Publisher('arduino_data_sync', DataControl, queue_size=10) # Data Control
    pub_motor = rospy.Publisher('motor_out_array', IntArray, queue_size=10) # Motor Control
    
    rospy.Service('server_motor_playback', MotorBoost, service_motor) # Hareket Komutlari

    rospy.Subscriber("motorIncomingData", MotorInArray, callbackMotor)

    rospy.init_node('motor_command_server', anonymous=True)

    rate = rospy.Rate(100)

    rospy.loginfo("READY: Motor Playback Server")

    test()

    rospy.spin()



if __name__ == '__main__':
    try:
        main()
    except rospy.ROSInterruptException:
        pass
