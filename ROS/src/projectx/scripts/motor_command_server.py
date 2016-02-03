#!/usr/bin/python

import rospy
import thread
import subprocess
import time
from projectx.msg import *
from projectx.srv import *
from std_msgs.msg import String

motor_values = {}
start = 0

def motor(komut):
    global pub, rate

    f = open("/home/rock/Motor_Test.txt","r")
    data = IntArray()

    for line in iter(f):
    	try:
            id = line.split(':')

            motor_id = int(id[1])
            motor_pos = int(id[3])
            
            data.data.append(motor_pos)
            
            print "ID: " +str(motor_id)+" POS: "+str(motor_pos)

            if motor_id == 20:
                print data
                pub.publish(data)
                rate.sleep()
                rospy.loginfo("Publisher")
                
        except:
            data = IntArray()

    f.close()



def service_motor(req):
    global process, pub_sync, pub_motor, rate
    komut = req.in_data
    
    if komut == "play":

        process = start()

        time.sleep(2)

        thread_single(process, "on")
        rospy.loginfo("RME: ON")

        time.sleep(3)

        thread_single(process, "exit")
        rospy.loginfo("RME: EXIT")

    elif komut == "manual":

        sync_data = DataControl()
        sync_data.data = "motor"
        sync_data.value = [1]
        pub_sync.publish(sync_data)
        print "Published Data Control in Motor Command Server"
        rate.sleep()

    return_data = "OK" # Simdilik


    res = MotorBoostResponse()
    res.out_data = return_data
    return res




## TERMINAL: RME ##

def command_single(process, komut):
    process.stdin.write(komut)
    process.stdin.write('\n')
def thread_single(process, komut):
    try:
        thread.start_new_thread( command_single, (process, komut,) )
    except:
        print "Error: unable to start thread"
def thread_multi(process, komut, deger):
    try:
        thread.start_new_thread( command_single, (process, komut, deger,) )
    except:
        print "Error: unable to start thread"
def start():
    terminal = subprocess.Popen(["rme"], stdin=subprocess.PIPE, stdout=subprocess.PIPE)
    return terminal
    


def main():
    global pub_sync, pub_motor, rate, process

    pub_sync = rospy.Publisher('arduino_data_sync', DataControl, queue_size=10) # Data Control
    pub_motor = rospy.Publisher('motor_out_array', IntArray, queue_size=10) # Motor Control
    
    rospy.Service('server_motor_command', MotorBoost, service_motor) # Request


    rospy.init_node('motor_command_server', anonymous=True)

    rate = rospy.Rate(100)

    rospy.loginfo("READY: Motor Command Server")


    # Ilk acilista hazir olmasi icin aciliyor

    rospy.spin()



if __name__ == '__main__':
    try:
        main()
    except rospy.ROSInterruptException:
        pass
