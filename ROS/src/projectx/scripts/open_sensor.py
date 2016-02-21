#!/usr/bin/env python

import rospy
from projectx.msg import *

def talker():
    pub_sync = rospy.Publisher('arduino_data_sync', DataControl, queue_size=10) # Data Control

    rospy.init_node('talker_2', anonymous=True)
    

    sync_data = DataControl()
    sync_data.data = "sensor"
    sync_data.value = [1]
    pub_sync.publish(sync_data)

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass