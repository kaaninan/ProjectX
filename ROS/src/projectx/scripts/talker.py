#!/usr/bin/env python

import rospy
import subprocess
import time
import signal
import os
from std_msgs.msg import *
from projectx.msg import *

def main():
    rospy.init_node('talker', anonymous=True)
    
    rospy.loginfo("Aciliyor..")

    p = subprocess.Popen(["rosrun face_recognition Fserver"], bufsize=2048, shell=True, stdin=subprocess.PIPE, stdout=subprocess.PIPE, close_fds=True)
    time.sleep(1)
    p2 = subprocess.Popen(["rosrun face_recognition Fclient"], bufsize=2048, shell=True, stdin=subprocess.PIPE, stdout=subprocess.PIPE, close_fds=True)


    while not rospy.is_shutdown():
        rospy.spin()

    rospy.loginfo("Kapatiliyor..")
    os.killpg(os.getpgid(p.pid), signal.SIGTERM)
    os.killpg(os.getpgid(p2.pid), signal.SIGTERM)


if __name__ == '__main__':
    try:
        main()
    except rospy.ROSInterruptException:
        pass