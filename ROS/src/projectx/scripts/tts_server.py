#!/usr/bin/env python

import subprocess
import time
import os
import ros

#!/usr/bin/python

import rospy
import thread
import subprocess
import os
import time
from projectx.msg import *
from projectx.srv import *
from std_msgs.msg import *





p = subprocess.Popen(["espeak -vtr -p40 -s160","Selam"], bufsize=2048, shell=True, stdin=subprocess.PIPE, stdout=subprocess.PIPE, close_fds=True)
p.wait()




## TERMINAL: RME ##

def command_single(process, komut):
    process.stdin.write(komut)
    process.stdin.write('\n')

def command_multi(process, komut, deger):
    process.stdin.write(komut)
    process.stdin.write(' ')
    process.stdin.write(deger)
    process.stdin.write('\n')

def thread_single(process, komut):
    try:
        thread.start_new_thread( command_single, (process, komut,) )
    except:
        print "Error: unable to start thread"

def thread_multi(process, komut, deger):
    try:
        thread.start_new_thread( command_multi, (process, komut, deger,) )
    except:
        print "Error: unable to start thread"

def start():
    terminal = subprocess.Popen(["sudo","$HOME/ProjectX/Motion/Linux/project/rme/rme"], stdin=subprocess.PIPE, stdout=subprocess.PIPE)

    return terminal








# Main Service
def service_motion_command(req):

    komut = req.in_data
    
    if komut[:4] == "head":
        rospy.loginfo("Head Access Opened: "+ str(komut[5:]))

    return_data = "OK" # Simdilik

    res = MotorBoostResponse()
    res.out_data = return_data
    return res






def main():

    global rate

    rospy.Service('service_tts', MotorBoost, service_motion_command) # TTS Service
    

    rospy.init_node('tts_server', anonymous=True)
    rate = rospy.Rate(100)

    rospy.loginfo("READY: Text To Speech Server")

    rospy.spin()



if __name__ == '__main__':
    try:
        main()
    except rospy.ROSInterruptException:
        pass