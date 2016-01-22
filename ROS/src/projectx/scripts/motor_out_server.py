#!/usr/bin/env python
# license removed for brevity
import rospy
from projectx.msg import MotorOut

def talker():
    pub = rospy.Publisher('arduinoMotorOutgoing', MotorOut, queue_size=10)

    rospy.init_node('motor_out_server', anonymous=True)

    rate = rospy.Rate(10)

    a = 300

    while not rospy.is_shutdown():

        data = MotorOut()

        data.id = 1
        data.pos = a
        data.speed = 500
        data.torque = 1
        data.rw = 0
        data.action = 0
        
        rospy.loginfo(data)
        pub.publish(data)
        rate.sleep()

        a = a + 1

        if a == 600:
            a = 300

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass