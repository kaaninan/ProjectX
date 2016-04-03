#!/usr/bin/env python

import rospy
import thread
import os
import subprocess
import time

# Open HTTPS Server

def run(name):
	subprocess.Popen(["cd $HOME/ProjectX/Speak; ./http"], bufsize=2048, shell=True, stdin=subprocess.PIPE, stdout=subprocess.PIPE, close_fds=True)

def start():
	try:
		thread.start_new_thread( run, ("Thread_1",) )
	except:
		rospy.logerr("Error: unable to start thread")

	time.sleep(2)

	auth = rospy.get_param("/open_speak", "0")

	if auth == 1:
		rospy.loginfo("OK")
		subprocess.Popen(["cd $HOME/ProjectX/Speak/Script; ./run"], bufsize=2048, shell=True, stdin=subprocess.PIPE, stdout=subprocess.PIPE, close_fds=True)
	else:
		rospy.loginfo("NO")

	rospy.loginfo("STARTED: Speak Server")

	rospy.spin()

if __name__ == '__main__':
	rospy.init_node('speak_server', anonymous=True)
	start()