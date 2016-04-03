#!/usr/bin/env python

import rospy
from projectx.msg import *

def talker():
    pub = rospy.Publisher('/motor_out_single', MotorOut, queue_size=10)

    rospy.init_node('talker_head', anonymous=True)

    array = [512, 512, 400, 600, 512, 512, 512, 512, 480, 520, 400, 400, 440, 440, 430, 430, 512, 512, 512, 512]
    
    rate = rospy.Rate(80) # 10hz

    a = 1
    for i in array:
        data = MotorOut()
        data.id = int(a)
        data.pos = int(i)
        data.torque = -1

        pub.publish(data)
        rate.sleep()
        a = a + 1

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass