#!/usr/bin/env python

import rospy
from projectx.msg import *
from std_msgs.msg import *

# for PUBLISH
param_name = "/arduino_out_data_auth"

# Power Led ve Laser icin ON_OFF butonlari TEMP datalari gerektiriyor

def req_callback(data):
    global pub, power_powerled, power_laser
    
    hedef = data.data
    value = data.value

    print "Callback Data Sync in Arduino Data Control"

    # FADER PWM

    if hedef == "powerled":
        print "Out Data Power Led: " + str(value)
        gonder_array(value)

    elif hedef == "laser":
        data_out = int(value[0])
        print "Out Data Laser: " + str(data_out)
        gonder("laser", data_out)

    elif hedef == "buzzer":
        data_out = int(value[0])
        print "Out Data Buzzer: " + str(data_out)
        gonder("buzzer", data_out)


    ## TOGGLE (ON-OFF)

    elif hedef == "powerled_power":
        global p1, p2, p3
        auth = rospy.get_param(param_name, 1)
        power_powerled[0] = int(value[0])
        power_powerled[1] = int(value[1])
        power_powerled[2] = int(value[2])
        if power_powerled[0] == 0: t1 = 0
        else: t1 = p1
        if power_powerled[1] == 0: t2 = 0
        else: t2 = p2
        if power_powerled[2] == 0: t3 = 0
        else: t3 = p3
        gonder_data = IntArray()
        gonder_data = [t1, t2, t3]
        if  auth == 1:
            pub_led.publish(gonder_data)
            rate.sleep()

    elif hedef == "laser_power":
        global laser_temp, power_laser
        auth = rospy.get_param(param_name, 1)
        power_laser = int(value[0])
        t1 = 0
        if power_laser == 1: t1 = laser_temp
        gonder_laserdata = Int64()
        gonder_laserdata.data = t1
        if  auth == 1:
            pub_laser.publish(gonder_laserdata)
            rate.sleep()
            rospy.loginfo("laser_temp: "+ str(laser_temp))



def gonder(select, indata):
    global pub_buzzer, pub_laser, power_laser, rate, laser_temp
    auth = rospy.get_param(param_name, 1)
    print "Out Data Publish Single: " + str(indata)

    if select == "laser" and auth == 1:
        laser_temp = int(indata)
        gonder = Int64()
        if power_laser == 0: indata = 0
        gonder.data = indata
        pub_laser.publish(gonder)
        rate.sleep()

    elif select == "buzzer" and auth == 1:
        gonder_buzzer = Int64()
        gonder_buzzer.data = int(indata)
        pub_buzzer.publish(gonder_buzzer)
        rate.sleep()


def gonder_array(indata):
    global pub_led, power_powerled, rate, p1, p2, p3
    auth = rospy.get_param(param_name, 1)
    print "Out Data Publish Single: " + str(indata)

    gonder = IntArray()
    t1 = int(indata[0])
    t2 = int(indata[1])
    t3 = int(indata[2])

    # for temp data
    p1 = t1
    p2 = t2
    p3 = t3

    if power_powerled[0] == 0: t1 = 0
    if power_powerled[1] == 0: t2 = 0
    if power_powerled[2] == 0: t3 = 0

    gonder = [t1, t2, t3]

    if  auth == 1:
        pub_led.publish(gonder)
        rate.sleep()



def main():
    global pub_laser, pub_buzzer, pub_led, power_laser, power_powerled, rate, laser_temp

    laser_temp = 0
    power_laser = 0
    power_powerled = list()
    for number in range (0,3): power_powerled.append(0)

    pub_laser = rospy.Publisher('Aol', Int64, queue_size=10)
    pub_buzzer = rospy.Publisher('Aob', Int64, queue_size=10)
    pub_led = rospy.Publisher('Aop', IntArray, queue_size=10)

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