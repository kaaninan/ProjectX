#!/usr/bin/env python

import rospy
from std_msgs.msg import *

def talker():
    pub = rospy.Publisher('/service_tts', String, queue_size=10)

    rospy.init_node('talker', anonymous=True)
    
    rate = rospy.Rate(20) # 10hz
    
    data = String()
    data.data = "add:Selam"
    pub.publish(data)
    rate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass