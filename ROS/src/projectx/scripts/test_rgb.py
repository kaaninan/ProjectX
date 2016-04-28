#!/usr/bin/env python

import rospy
from projectx.msg import *

def talker():
    pub = rospy.Publisher('/arduino_out_data', DataControl, queue_size=10)

    rospy.init_node('talker', anonymous=True)
    
    
    data = DataControl()
    data.data = "powerled_1"
    data.value = [0]
    pub.publish(data)

    data = DataControl()
    data.data = "powerled_3"
    data.value = [5]
    pub.publish(data)


if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        passs