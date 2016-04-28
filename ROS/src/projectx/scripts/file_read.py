#!/usr/bin/python

import rospy
from projectx.msg import *
from std_msgs.msg import String

motor_values = {}
start = 0

def arduinoMotor():
    global pub, rate

    f = open("/home/rock/Motor_Test.txt","r")
    data = MotorOutSingleArray()

    for line in iter(f):
    	try:
            id = line.split(':')

            motor_id = int(id[1])
            motor_pos = int(id[3])
            
            data.id[motor_id] = motor_id
            data.pos[motor_id] = motor_pos
            
            print "ID: " +str(motor_id)+" POS: "+str(motor_pos)

            if motor_id == 20:
                pub.publish(data)
                rate.sleep()
                rospy.loginfo("Publisher")
                
        except:
            hata = 1

            
	

    f.close()




def talker():
    global pub, rate
    pub = rospy.Publisher('arduinoMotorOutgoingArray', MotorOutSingleArray, queue_size=10)

    rospy.init_node('motor_out_server_test2', anonymous=True)

    rate = rospy.Rate(50)

    rospy.loginfo("READY: Motor Outgoing Server Test")
    
    arduinoMotor()

    # while 1:
    #     

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
