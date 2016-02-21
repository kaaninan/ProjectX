#!/usr/bin/env python

import rospy
from projectx.msg import *

def talker():
    pub = rospy.Publisher('arduino_out_data', DataControl, queue_size=10)

    rospy.init_node('talker', anonymous=True)
    
    rate = rospy.Rate(10) # 10hz
    
    a = 0

    while not rospy.is_shutdown():
        data = DataControl()
        data.data = "powerled"
        data.value = [a, 0, 0]
        rospy.loginfo(data)
        pub.publish(data)
        rate.sleep()
        a = a + 1
        if a == 255:
            a = 0

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass