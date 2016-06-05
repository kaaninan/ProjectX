#!/usr/bin/env python
import rospy
import time
from projectx.msg import *
from std_msgs.msg import *


def callback(data):
    global pub_tts, pub_motion, a, pub_head

    name = data.common.name
    value = data.value
    
    #rospy.loginfo(name)
    #rospy.loginfo(value)

    if name == "wink_left":
        pass
    elif name == "wink_right":
        pass
    elif name == "look_right":
        pass
    elif name == "look_left":
        pass
    elif name == "blink":
        if value == 1.0:
            a = a + 1
            if a == 5:
                a = 0
                rospy.loginfo("blink")
                data = IntArray()
                data.deger = [512, 512]
                pub_head.publish(data)
                time.sleep(0.5)

                data = String()
                data.data = "add:Merhaba, benim adim Robomental"
                pub_tts.publish(data)
                time.sleep(0.5)

                data = String()
                data.data = "gel"
                pub_motion.publish(data)
                time.sleep(0.5)

                data = IntArray()
                data.deger = [512, 460]
                pub_head.publish(data)

                time.sleep(0.8)

                data = IntArray()
                data.deger = [512, 512]
                pub_head.publish(data)

                data = String()
                data.data = "normal"
                pub_motion.publish(data)
                time.sleep(0.5)

                time.sleep(2)

    elif name == "idea_1":
        if value == 1.0:
            rospy.loginfo("I1")
            data = String()
            data.data = "add:Merhaba, sizden biraz su istiyorum."
            pub_tts.publish(data)

            data = String()
            data.data = "gel"
            pub_motion.publish(data)
            time.sleep(3)

            data = String()
            data.data = "normal"
            pub_motion.publish(data)
            time.sleep(0.5)

            time.sleep(5)

    elif name == "idea_2":
        if value == 1.0:
            rospy.loginfo("I2")
            data = String()
            data.data = "add:Disari cikmak istiyorum"
            pub_tts.publish(data)

            data = String()
            data.data = "gel"
            pub_motion.publish(data)
            time.sleep(4)

            data = String()
            data.data = "normal"
            pub_motion.publish(data)

            time.sleep(5)



def listener():
    global pub_tts, pub_motion, a, pub_head

    a = 0

    rospy.Subscriber("/touchosc/mind/blink", ScalableControl, callback)
    rospy.Subscriber("/touchosc/mind/look_left", ScalableControl, callback)
    rospy.Subscriber("/touchosc/mind/look_right", ScalableControl, callback)
    rospy.Subscriber("/touchosc/mind/wink_left", ScalableControl, callback)
    rospy.Subscriber("/touchosc/mind/wink_right", ScalableControl, callback)
    rospy.Subscriber("/touchosc/mind/idea_1", ScalableControl, callback)
    rospy.Subscriber("/touchosc/mind/idea_2", ScalableControl, callback)

    pub_head = rospy.Publisher('/motor_head_position', IntArray, queue_size=10)

    pub_tts = rospy.Publisher('/service_tts', String, queue_size=10)
    pub_motion = rospy.Publisher('/service_motion_command', String, queue_size=10)

    pub = rospy.Publisher('/arduino_data_sync', DataControl, queue_size=10)

    rospy.loginfo("READY: ROS Mind OSC Started")
    
    time.sleep(2)

    data = DataControl()
    data.data = "motor"
    data.value = [1]

    pub.publish(data)
    pub.publish(data)

    rospy.spin()


def main():
    global pub, rate
    rospy.init_node('osc_mind_incoming', anonymous=True)
    
    pub = rospy.Publisher('arduino_out_data', DataControl, queue_size=10)
    rate = rospy.Rate(100)
    
    listener()


if __name__ == '__main__':
    main()
