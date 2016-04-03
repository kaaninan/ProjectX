#!/usr/bin/env python

import rospy
from projectx.msg import *

def talker():
    pub = rospy.Publisher('/motor_head_position', IntArray, queue_size=10)

    rospy.init_node('talker_head', anonymous=True)
    
    rate = rospy.Rate(20) # 10hz
    
    a = 300
    while not rospy.is_shutdown():
        
        data = IntArray()
        data.deger = [a, 512]

        a = a + 3

        if a > 700: a = 300

        pub.publish(data)
        rate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass