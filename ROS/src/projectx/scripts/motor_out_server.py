#!/usr/bin/env python
import rospy
from projectx.msg import MotorOut
from projectx.msg import MotorOutArray
from std_msgs.msg import String

motor_values = {}

def arduinoMotor():
    global pub, rate
    a = 500
    b = 1

    while not rospy.is_shutdown():

        data = MotorOut()

        data.id = b
        data.pos = a
        data.speed = 500
        data.torque = 1
        data.rw = 0
        data.action = 0
        
        pub.publish(data)
        rate.sleep()

        b = b + 1
        a = a + 1

        if b == 20:
            b = 1

        if a == 550:
            a = 500


def motor_string_data_callback(data):
    rospy.loginfo(rospy.get_caller_id() + "I heard %s", data.data)

def motor_out_chat_callback(data):
    global motor_values

    for i in range(1,21):
        motor_values[i] = {"pos":data.pos[i], "speed":data.speed[i], "torque": data.torque[i], "rw": data.rw[i], "action": data.action[i]}


def talker():
    global pub, rate
    pub = rospy.Publisher('arduinoMotorOutgoing', MotorOut, queue_size=10)
    rospy.Subscriber("motor_string_data", String, motor_string_data_callback)
    rospy.Subscriber("motor_out_chat_server", MotorOutArray, motor_out_chat_callback)

    rospy.init_node('motor_out_server', anonymous=True)

    rate = rospy.Rate(100)

    arduinoMotor()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass