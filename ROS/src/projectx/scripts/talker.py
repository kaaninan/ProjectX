#!/usr/bin/env python

import rospy
from std_msgs.msg import *
from projectx.msg import *

def talker():
    pub = rospy.Publisher('/motor_head_position', IntArray, queue_size=10)

    rospy.init_node('talker', anonymous=True)
    
    rate = rospy.Rate(100) # 10hz

    a = 300

    while not rospy.is_shutdown():
        data = IntArray()
        data.deger = [a,512]
        pub.publish(data)
        rate.sleep()

        a = a+1

        if a == 700:
            a = 300

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass