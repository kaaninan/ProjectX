#!/usr/bin/env python

import rospy
from projectx.msg import *

def talker():
    pub = rospy.Publisher('/motor_out_array', IntArray, queue_size=10)

    rospy.init_node('talker_head', anonymous=True)
    
    rate = rospy.Rate(1) # 10hz

    data = IntArray()
    data.deger =[512, 512, 500, 500, 512, 512, 512, 512, 500, 530, 405, 405, 450, 450, 430, 430, 500, 530, 512, 512]

    while 1:
        pub.publish(data)
        rate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass