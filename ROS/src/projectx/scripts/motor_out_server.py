#!/usr/bin/env python
import rospy
from projectx.msg import *
from std_msgs.msg import String

motor_values = {}
start = 0


def default_deger():
    global motor_values
    for i in range(1,21):
        motor_values[i] = {"pos":512, "speed":0, "torque": 0, "rw": 1, "action": 0}

def arduinoMotor():
    global pub, rate, start
    
    motor_id = 1

    while start:

        global motor_values

        data = MotorOut()

        data.id = int(motor_id)
        data.pos = int(motor_values[motor_id].get("pos"))
        data.speed = 0
        data.torque = int(motor_values[motor_id].get("torque"))
        data.rw = int(motor_values[motor_id].get("rw"))
        data.action = 0
        
        #print("PUBLISH: "+ str(data.id) + " - " + str(data.pos) + " - " + str(data.speed) + " - " + str(data.torque) + " - " + str(data.rw) + " - " + str(data.action))

        pub.publish(data)
        rate.sleep()

        motor_id = motor_id + 1
        if motor_id == 20:
            motor_id = 1


def motor_string_data_callback(data):
    rospy.loginfo(rospy.get_caller_id() + "I heard %s", data.data)



def motor_out_single_callback(data):
    global motor_values, start
    start = 1
    motor_values[data.id] = {"pos":data.pos, "speed":data.speed, "torque": data.torque, "rw": data.rw, "action": data.action}


def motor_out_chat_callback2(data):
    global motor_values

    for i in range(1,21):
        motor_values[i] = {"pos":data.pos[i], "speed":data.speed[i], "torque": data.torque[i], "rw": data.rw[i], "action": data.action[i]}


def talker():
    global pub, rate
    pub = rospy.Publisher('arduinoMotorOutgoing', MotorOut, queue_size=10)
    rospy.Subscriber("motor_string_data", String, motor_string_data_callback)
    rospy.Subscriber("motor_out_single_server", MotorOut, motor_out_single_callback)

    rospy.init_node('motor_out_server', anonymous=True)

    rate = rospy.Rate(100)

    rospy.loginfo("READY: Motor Outgoing Server")

    default_deger()

    while 1:
        arduinoMotor()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass