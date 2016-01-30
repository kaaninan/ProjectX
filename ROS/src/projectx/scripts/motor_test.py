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
    
    b = 400
    ilerle = 1
    gerile = 0

    while 1:

        global motor_values

        data = MotorOut()

        data.id = 1
        data.pos = b
        data.speed = 0
        data.torque = 1
        data.rw = 0
        data.action = 0

        data2 = MotorOut()

        data2.id = 2
        data2.pos = b
        data2.speed = 0
        data2.torque = 1
        data2.rw = 0
        data2.action = 0
        
        print("PUBLISH: "+ str(data.id) + " - " + str(data.pos) + " - " + str(data.speed) + " - " + str(data.torque) + " - " + str(data.rw) + " - " + str(data.action))

        pub.publish(data)
        rate.sleep()
        pub.publish(data2)
        rate.sleep()

        if ilerle == 1:
            b = b + 1
            if b == 600:
                ilerle = 0
        elif ilerle == 0:
            b = b - 1
            if b == 400:
                ilerle = 1




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

    rospy.init_node('motor_out_server_test', anonymous=True)

    rate = rospy.Rate(50)

    rospy.loginfo("READY: Motor Outgoing Test Server")

    default_deger()
    
    arduinoMotor()

    # while 1:
    #     

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass