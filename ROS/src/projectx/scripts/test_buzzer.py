#!/usr/bin/env python

import rospy
from projectx.msg import *

def talker():
    pub = rospy.Publisher('/arduino_out_data', DataControl, queue_size=10)

    rospy.init_node('talker', anonymous=True)
    
    rate = rospy.Rate(20) # 10hz
    a = 0
    while not rospy.is_shutdown():
        data = DataControl()
        data.data = "buzzer"
        data.value = [a]
        if a == 0: a = 1
        else: a = 0
        pub.publish(data)
        rate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass