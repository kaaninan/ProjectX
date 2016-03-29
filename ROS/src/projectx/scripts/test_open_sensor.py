#!/usr/bin/env python

import rospy
from projectx.msg import *

def talker():
    pub = rospy.Publisher('/arduino_data_sync', DataControl, queue_size=10)

    rospy.init_node('talker', anonymous=True)
    
    data = DataControl()
    data.data = "sensor"
    data.value = [1]

    pub.publish(data)

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass