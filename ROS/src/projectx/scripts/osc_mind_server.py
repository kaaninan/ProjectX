#!/usr/bin/env python
import rospy
from projectx.msg import *


def callback(data):
    name = data.common.name
    value = data.value
    rospy.loginfo(name)
    rospy.loginfo(value)

    if name == "blink":
        if value == 1.0:
            rospy.loginfo("Blink")
        
    elif name == "look_left":
        if value == 1.0:
            rospy.loginfo("Look Left")


def listener():

    rospy.Subscriber("/touchosc/mind/blink", ScalableControl, callback)
    rospy.Subscriber("/touchosc/mind/look_left", ScalableControl, callback)
    rospy.Subscriber("/touchosc/mind/look_right", ScalableControl, callback)
    rospy.Subscriber("/touchosc/mind/wink_left", ScalableControl, callback)
    rospy.Subscriber("/touchosc/mind/wink_right", ScalableControl, callback)
    rospy.Subscriber("/touchosc/mind/idea_1", ScalableControl, callback)
    rospy.Subscriber("/touchosc/mind/idea_2", ScalableControl, callback)

    rospy.loginfo("READY: ROS Mind OSC Started")
    
    rospy.spin()


def main():
    global pub, rate
    rospy.init_node('osc_mind_incoming', anonymous=True)
    
    pub = rospy.Publisher('arduino_out_data', DataControl, queue_size=10)
    rate = rospy.Rate(100)
    
    listener()


if __name__ == '__main__':
    main()
