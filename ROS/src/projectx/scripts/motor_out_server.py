#!/usr/bin/env python
import rospy
from projectx.msg import *
from std_msgs.msg import String


def motor_out_single_callback(data):
    # rospy.loginfo("Motor Out Server PUB")
    global pub_single, rate
    pub_single.publish(data)
    rate.sleep()
    

def motor_out_array_callback(data):
    # rospy.loginfo("Motor Out Server Array PUB")
    global pub_pos, rate
    pub_pos.publish(data)
    rate.sleep()


def talker():
    global pub_pos, pub_single, rate

    pub_pos = rospy.Publisher('Amop', IntArray, queue_size=10) # Motor (Position)
    pub_single = rospy.Publisher('Amot', MotorOut, queue_size=10) # Single Motor (Torque) or (Position)
    
    rospy.Subscriber("motor_out_single", MotorOut, motor_out_single_callback) # Single (POS) or (Torque) <- RME
    rospy.Subscriber("motor_out_array", IntArray, motor_out_array_callback) # Array POS <- Motor Command Server

    rospy.init_node('motor_out_server', anonymous=True)

    rate = rospy.Rate(40)

    rospy.loginfo("READY: Motor Outgoing Server")

    rospy.spin()
    

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass