#!/usr/bin/env python

import rospy
from projectx.msg import *
from std_msgs.msg import *
import time
import thread
import threading


hiz = 8


# Subscriber
def service_sub(req):
    global ok_rgb

    komut = req.data
    
    if komut[:4] == "auto":
        veri = int(komut[5:])
        if veri == 1: ok_rgb = 1
        else: ok_rgb = 0

    elif komut[:3] == "man":
        veri = str(komut[4:])
        ok_rgb = 0
        rgb_manual(veri)
        



def rgb_manual(renk):

    if renk == "red":
        rgbColour = list()
        rgbColour.append(0)
        rgbColour.append(255)
        rgbColour.append(255)
        publish(rgbColour)

    elif renk == "green":
        rgbColour = list()
        rgbColour.append(255)
        rgbColour.append(0)
        rgbColour.append(255)
        publish(rgbColour)

    elif renk == "blue":
        rgbColour = list()
        rgbColour.append(255)
        rgbColour.append(255)
        rgbColour.append(0)
        publish(rgbColour)

    elif renk == "light_blue":
        rgbColour = list()
        rgbColour.append(255)
        rgbColour.append(100)
        rgbColour.append(100)
        publish(rgbColour)

    elif renk == "white":
        rgbColour = list()
        rgbColour.append(170)
        rgbColour.append(10)
        rgbColour.append(30)
        publish(rgbColour)

    elif renk == "none":
        rgbColour = list()
        rgbColour.append(255)
        rgbColour.append(255)
        rgbColour.append(255)
        publish(rgbColour)



def rgb_oto():
  rgbColour = list()

  rgbColour.append(255)
  rgbColour.append(0)
  rgbColour.append(0)

  for decColour in range(3):

    if decColour == 2:
        incColour = 0
    else:
        incColour = decColour + 1

    for a in range(255):
        rgbColour[decColour] -= 1;
        rgbColour[incColour] += 1;

        publish_time(rgbColour[0],rgbColour[1],rgbColour[2])





pub_ok = 1

def publish_time(a,b,c):
    global pub, rate, pub_ok, hiz, access

    if pub_ok % hiz == 0:
        data = DataControl()
        data.data = "rgb"
        data.value = [a,b,c]

        pub.publish(data)
        rate.sleep()

    pub_ok = pub_ok + 1

    if pub_ok > 1000:
        pub_ok = 1
    


def publish(array):
    global pub, rate, access

    data = DataControl()
    data.data = "rgb"
    data.value = [array[0],array[1],array[2]]

    pub.publish(data)
    rate.sleep()





def talker():
    global pub, rate, thr, ok_rgb

    ok_rgb = 0

    pub = rospy.Publisher('/arduino_out_data', DataControl, queue_size=10)

    rospy.Subscriber("/arduino_rgb", String, service_sub)

    rospy.init_node('talker_rgb', anonymous=True)

    rate = rospy.Rate(20)

    rospy.loginfo("Ready: RGB Server")

    while not rospy.is_shutdown():
        while ok_rgb == 1:
            rgb_oto()

    



if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass