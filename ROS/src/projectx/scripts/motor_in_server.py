#!/usr/bin/env python
import rospy
from projectx.msg import *
from std_msgs.msg import *
import thread
import time

motor_values = {}



def publish_data(thread_name,delay):
    global motor_values

    while  1:
        motorData = MotorInArray()

        try:
            for i in range(1,21):
                # motorData.temp.append(int(motor_values[i].get("temp")))
                # motorData.voltage.append(int(motor_values[i].get("voltage")))
                motorData.pos.append(int(motor_values[i].get("pos")))
            global pub, rate
            # rospy.loginfo("Motor In Server")
            # rospy.loginfo(motorData)
            pub.publish(motorData)
            rate.sleep()
        except:
            tamam = 0

            






def callback(data):
    
    global motor_values

    motor_id = int(data.id - 1)
    if int(data.id) == 1: motor_id = 20

    motor_values[motor_id] = {"pos": int(data.deger)}

    # rospy.loginfo(data)
    # rospy.loginfo(motor_values)


def listener():
    
    rospy.init_node('motor_values_listener', anonymous=True)
    
    rospy.Subscriber("arduino_in_motor", Hash, callback)

    try:
        time.sleep(4)
        thread.start_new_thread(publish_data, ("Thread-1",2))
    except:
        rospy.logerr("Thread Error");
    
    global pub, rate
    
    pub = rospy.Publisher('motor_incoming_data', MotorInArray, queue_size=10)
    rate = rospy.Rate(100)

    rospy.loginfo("READY: Motor Incoming Server")
    
    rospy.spin()

if __name__ == '__main__':
    listener()