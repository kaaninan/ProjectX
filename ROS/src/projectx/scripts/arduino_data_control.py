#!/usr/bin/env python

import rospy
from projectx.msg import *

# [x,y,z] Subscriber Data

# x => Sensor
# y => Gyro
# z => Servo

# Default
data_array = [0,0,0]

def req_callback(data):
    global pub, data_array
    
    hedef = data.data
    value = data.value

    print "Callback Data Sync in Arduino Data Control"

    if hedef == "motor":
        data_array[2] = int(value[0])
        print "Data Control Opened Motor: " + str(data_array[2])
    elif hedef == "sensor":
        data_array[0] = int(value[0])
        print "Data Control Opened Sensor: " + str(data_array[0])

    gonder()


def gonder():
    global pub, data_array

    print "Data Control Publish Motor: " + str(data_array)

    gonder = IntArray()
    gonder = [data_array[0], data_array[1], data_array[2]]

    pub.publish(gonder)




def main():
    global pub

    pub = rospy.Publisher('Adc', IntArray, queue_size=10)
    rospy.Subscriber("arduino_data_sync", DataControl, req_callback)

    rospy.init_node('arduino_data_control', anonymous=True)

    rospy.loginfo("READY: Arduino Data Control")

    rospy.spin()
        

if __name__ == '__main__':
    try:
        main()        
    except rospy.ROSInterruptException:
        passs