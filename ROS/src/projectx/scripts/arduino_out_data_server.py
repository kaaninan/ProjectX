#!/usr/bin/env python

import rospy
from projectx.msg import *
from std_msgs.msg import *


def req_callback(data):
    global pub
    
    hedef = data.data
    value = data.value

    print "Callback Data Sync in Arduino Data Control"

    if hedef == "powerled":
        print "Out Data Power Led: " + str(value)
        gonder_array(value)

    elif hedef == "laser":
        data_out = int(value[0])
        print "Out Data Laser: " + str(data_out)
        gonder("laser", data)

    elif hedef == "buzzer":
        data_out = int(value[0])
        print "Out Data Buzzer: " + str(data_out)
        gonder("buzzer", data)



def gonder(select, indata):
    global pub_buzzer, pub_laser
    auth = rospy.get_param("/arduino_out_data_auth", 1)
    print "Out Data Publish Single: " + str(indata)
    gonder = Int64()
    gonder.data = indata
    if select == "laser" and auth == 1:
        pub_laser.publish(gonder)
    elif select == "buzzer":
        pub_buzzer.publish(gonder)


def gonder_array(indata):
    global pub_led
    auth = rospy.get_param("/arduino_out_data_auth", 1)
    print "Out Data Publish Single: " + str(indata)
    gonder = IntArray()
    gonder = [indata[0], indata[1], indata[2]]
    if  auth == 1:
        pub_led.publish(gonder)



def main():
    global pub_laser, pub_buzzer, pub_led

    pub_laser = rospy.Publisher('Aol', Int64, queue_size=10)
    pub_buzzer = rospy.Publisher('Aob', Int64, queue_size=10)
    pub_led = rospy.Publisher('Aop', IntArray, queue_size=10)

    rospy.Subscriber("arduino_out_data", DataControl, req_callback)

    rospy.init_node('arduino_out_data_server', anonymous=True)

    rospy.loginfo("READY: Arduino Out Data Server")

    rospy.spin()
        

if __name__ == '__main__':
    try:
        main()        
    except rospy.ROSInterruptException:
        passs