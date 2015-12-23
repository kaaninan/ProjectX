#! /usr/bin/env python

import sys
import rospy
from projectx.srv import *

def temp_client():
	rospy.wait_for_service('sensor_temp_service')
	try:
		temp = rospy.ServiceProxy('sensor_temp_service', SensorTemp)
		resp1 = temp()
		return resp1.nem
	except rospy.ServiceException, e:
		return "Serivice Call Failed"
		
		
if __name__ == "__main__":
	print "%f"%(temp_client())
