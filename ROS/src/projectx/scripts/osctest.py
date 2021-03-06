#!/usr/bin/env python
import rospy
from projectx.msg import *


def callback_rotary():
    name = data.common.name
    value = data.value
    rospy.loginfo(name[5:])
    rospy.loginfo(value)

def callback_toggle():
    name = data.common.name
    value = data.value
    rospy.loginfo(name[5:])
    rospy.loginfo(value)


def callback_multitoggle():
    pass

def callback_push():
    name = data.common.name
    value = data.value
    rospy.loginfo(name[5:])
    rospy.loginfo(value)

def callback_multipush():
    pass

def callback_encoder():
    name = data.common.name
    value = data.value
    rospy.loginfo(name[5:])
    rospy.loginfo(value)

def callback_xy_gyro():
    pass

def callback_xy_motion():
    pass

def callback_xy_head():
    pass

def callback_fader():
    name = data.common.name
    value = data.value
    rospy.loginfo(name[5:])
    rospy.loginfo(value)

def callback_multifader():
    pass

def listener():

    # ROTARY (Basligin Altinda)
    rot[0] = "touchosc/main/rotary1"
    rot[1] = "touchosc/main/rotary2"
    rot[2] = "touchosc/main/rotary3"
    rospy.Subscriber(rot[0], ScalableControl, callback_rotary)
    rospy.Subscriber(rot[1], ScalableControl, callback_rotary)
    rospy.Subscriber(rot[2], ScalableControl, callback_rotary)

    # TOGGLE (Ust Sira)
    taslak = "touchosc/main/toggle"
    for number in range(17,21):
        taslak1 = taslak + str(number)
        rospy.Subscriber(taslak1, ScalableControl, callback_toggle)

    # TOGGLE (Orta Sira)
    taslak = "touchosc/main/toggle"
    for number in range(9,13):
        taslak1 = taslak + str(number)
        rospy.Subscriber(taslak1, ScalableControl, callback_toggle)

    # TOGGLE (Alt Sira)
    taslak = "touchosc/main/toggle"
    for number in range(21,25):
        taslak1 = taslak + str(number)
        rospy.Subscriber(taslak1, ScalableControl, callback_toggle)

    # TOGGLE
    rospy.Subscriber("/touchosc/main/toggle_lazer", ScalableControl, callback_toggle)
    rospy.Subscriber("/touchosc/main/multitoggle_led", MultiButton, callback_multitoggle)
    rospy.Subscriber("/touchosc/main/multitoggle_2", MultiButton, callback_multitoggle) # Sari - Buzzerin ustunde
    rospy.Subscriber("/touchosc/main/multitoggle_auto", MultiButton, callback_multitoggle) # Auto - motionun yaninda

    # PUSH
    rospy.Subscriber("/touchosc/main/push_buzzer", ScalableControl, callback_push)
    rospy.Subscriber("/touchosc/main/push_start", ScalableControl, callback_push)
    rospy.Subscriber("/touchosc/main/multipush_sifre", MultiPush, callback_multipush)

    # ENCODER
    rospy.Subscriber("/touchosc/main/encoder1", ScalableControl, callback_encoder)

    # XY
    rospy.Subscriber("/touchosc/main/xy_gyro", XYPad, callback_xy_gyro)
    rospy.Subscriber("/touchosc/main/multixy_motion", MultiXYPad, callback_xy_motion)
    rospy.Subscriber("/touchosc/main/multixy_head", MultiXYPad, callback_xy_head)

    # FADER
    rospy.Subscriber("/touchosc/main/fader1", ScalableControl, callback_fader) # Head XY'nin yaninda
    rospy.Subscriber("/touchosc/main/fader_laser", ScalableControl, callback_fader)
    rospy.Subscriber("/touchosc/main/multifader_led", MultiFader, callback_multifader)


    rospy.loginfo("ROS OSC Started")
    
    rospy.spin()


def main():
    rospy.init_node('osc_incoming', anonymous=True)
    listener()


if __name__ == '__main__':
    main()
