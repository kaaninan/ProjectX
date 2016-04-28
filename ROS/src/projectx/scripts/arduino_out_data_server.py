#!/usr/bin/env python

import rospy
from projectx.msg import *
from std_msgs.msg import *



def req_callback(data):
    
    hedef = data.data
    value = data.value

    print "Callback Data Sync in Arduino Data Control"

    # SECENEKLER

    if hedef == "rgb":
        print "Out Data RGB: " + str(value)
        gonder_array_rgb(value)

    elif hedef == "buzzer":
        data_out = int(value[0])
        print "Out Data Buzzer: " + str(data_out)
        gonder_buzzer(data_out)

    elif hedef == "powerled_1":
        data_out = int(value[0])
        print "Out Data Led: " + str(data_out)
        gonder_led_1(data_out)

    elif hedef == "powerled_2":
        data_out = int(value[0])
        print "Out Data Led: " + str(data_out)
        gonder_led_2(data_out)

    elif hedef == "powerled_3":
        data_out = int(value[0])
        print "Out Data Led: " + str(data_out)
        gonder_led_3(data_out)



def gonder_array_rgb(indata):
    global pub_rgb, rate
    print "Out Data Publish RGB: " + str(indata)
    gonder = IntArray()
    t1 = int(indata[0])
    t2 = int(indata[1])
    t3 = int(indata[2])
    gonder = [t1, t2, t3]
    pub_rgb.publish(gonder)
    rate.sleep()


def gonder_buzzer(indata):
    global pub_buzzer, rate
    gonder = Int64()
    gonder.data = int(indata)
    pub_buzzer.publish(gonder)
    rate.sleep()


def gonder_led_1(indata):
    global pub_led_1, rate
    gonder = Int64()
    gonder.data = int(indata)
    pub_led_1.publish(gonder)
    rate.sleep()

def gonder_led_2(indata):
    global pub_led_2, rate
    gonder = Int64()
    gonder.data = int(indata)
    pub_led_2.publish(gonder)
    rate.sleep()

def gonder_led_3(indata):
    global pub_led_3, rate
    gonder = Int64()
    gonder.data = int(indata)
    pub_led_3.publish(gonder)
    rate.sleep()



def main():
    global pub_led_1, pub_led_2, pub_led_3, pub_buzzer, pub_rgb, rate

    # Publisher
    pub_rgb = rospy.Publisher('arduino_out_rgb', IntArray, queue_size=10)
    pub_buzzer = rospy.Publisher('arduino_out_buzzer', Int64, queue_size=10)
    pub_led_1 = rospy.Publisher('arduino_out_led_1', Int64, queue_size=10)
    pub_led_2 = rospy.Publisher('arduino_out_led_2', Int64, queue_size=10)
    pub_led_3 = rospy.Publisher('arduino_out_led_3', Int64, queue_size=10)


    # Subscriber    
    rospy.Subscriber("arduino_out_data", DataControl, req_callback)

    rospy.init_node('arduino_out_data_server', anonymous=True)

    rospy.loginfo("READY: Arduino Out Data Server")
    
    rate = rospy.Rate(100)

    rospy.spin()
        

if __name__ == '__main__':
    try:
        main()        
    except rospy.ROSInterruptException:
        passs