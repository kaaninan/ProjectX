#!/usr/bin/python

import rospy
import thread
import subprocess
import os
import time
from projectx.msg import *
from projectx.srv import *
from std_msgs.msg import *


def motor():
    global pub_motor, rate

    f = open("/home/rock/Motor_Test.txt","r")
    data = IntArray()

    for line in iter(f):
    	try:
            id = line.split(':')

            motor_id = int(id[1])
            motor_pos = int(id[3])
            
            data.deger.append(motor_pos)
            
            print "ID: " +str(motor_id)+" POS: "+str(motor_pos)

            if motor_id == 20:
                print data
                pub_motor.publish(data)
                rate.sleep()
                rospy.loginfo("Publisher")
                data = IntArray()
                
        except:
            rospy.loginfo("HATA")
            data = IntArray()

    f.close()




# RME'den Play Bitince
def sub_played(data):
    global played
    rospy.loginfo("Play Finished")
    played = data.data


def service_motor(req):
    global process, pub_sync, pub_motor, rate, played
    komut = req.in_data

    played = 0
    
    if komut == "play":

        os.system("sudo rm /home/rock/Motor_Test.txt")

        process = start()
        time.sleep(2)

        thread_single(process, "on")
        rospy.loginfo("RME: ON")
        time.sleep(4)

        thread_multi(process, "page", "0")
        rospy.loginfo("RME: ON")
        time.sleep(2)

        thread_single(process, "play")
        rospy.loginfo("RME: PLAY")

        time.sleep(10)

        thread_single(process, "exit")
        rospy.loginfo("RME: EXIT")

        # while 1:
        #     global played
        #     if played == 1:
        #         print "PLAY BITTI"
        #         time.sleep(3)
                
        #         thread_single(process, "exit")
        #         rospy.loginfo("RME: EXIT")
        #         played = 0
        #         break;

    elif komut == "manual":
        sync_data = DataControl()
        sync_data.data = "motor"
        sync_data.value = [1]
        pub_sync.publish(sync_data)
        print "Published Data Control in Motor Command Server"
        rate.sleep()

    elif komut == "start":
        process = start()
        time.sleep(5)

        thread_single(process, "exit")
        rospy.loginfo("RME: EXIT")

    elif komut == "file":
        motor()
        rospy.loginfo("FILE READ - PLAY")

    elif komut == "exit":
        thread_single(process, "exit")
        rospy.loginfo("RME: EXIT")


    return_data = "OK" # Simdilik

    res = MotorBoostResponse()
    res.out_data = return_data
    return res




## TERMINAL: RME ##

def command_single(process, komut):
    process.stdin.write(komut)
    process.stdin.write('\n')

def command_multi(process, komut, deger):
    process.stdin.write(komut)
    process.stdin.write(' ')
    process.stdin.write(deger)
    process.stdin.write('\n')

def thread_single(process, komut):
    try:
        thread.start_new_thread( command_single, (process, komut,) )
    except:
        print "Error: unable to start thread"

def thread_multi(process, komut, deger):
    try:
        thread.start_new_thread( command_multi, (process, komut, deger,) )
    except:
        print "Error: unable to start thread"

def start():
    terminal = subprocess.Popen(["sudo","/home/rock/ProjectX/Motion/Linux/project/rme/rme"], stdin=subprocess.PIPE, stdout=subprocess.PIPE)
    
    # line = terminal.stdout.readline()
    # print line

    return terminal
    


def main():
    global pub_sync, pub_motor, rate, process

    pub_sync = rospy.Publisher('arduino_data_sync', DataControl, queue_size=10) # Data Control
    pub_motor = rospy.Publisher('motor_out_array', IntArray, queue_size=10) # Motor Control
    
    rospy.Subscriber("motor_out_played", Int64, sub_played) # RME Play Finished

    rospy.Service('server_motor_command', MotorBoost, service_motor) # Hareket Komutlari


    rospy.init_node('motor_command_server', anonymous=True)

    rate = rospy.Rate(100)

    rospy.loginfo("READY: Motor Command Server")

    rospy.spin()



if __name__ == '__main__':
    try:
        main()
    except rospy.ROSInterruptException:
        pass
