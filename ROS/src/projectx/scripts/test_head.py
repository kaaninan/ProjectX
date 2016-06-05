#!/usr/bin/env python

import rospy
from projectx.msg import *
import random
import time

def talker():
    pub = rospy.Publisher('/motor_head_position', IntArray, queue_size=10)

    rospy.init_node('talker_head', anonymous=True)
    
    rate = rospy.Rate(20) # 10hz
    
    a = 300
    while not rospy.is_shutdown():
        
        c = random.randint(400, 600)
        d = random.randint(490,520)

        data = IntArray()
        data.deger = [c, d]

        
        a = a + 3

        if a > 700: a = 300

        time.sleep(2)

        pub.publish(data)
        rate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass