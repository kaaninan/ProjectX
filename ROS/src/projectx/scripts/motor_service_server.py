#!/usr/bin/env python

import rospy
from projectx.srv import *
from projectx.msg import *

def handle_service(req):
	global motor_data
	parseList = req.in_data.split(":")
	veri_turu = parseList[0]
	motor_id = parseList[1]
	komut = parseList[2]

	if veri_turu == "read_present_pos":
		return_data = motor_data.pos[int(motor_id)-1]

	elif veri_turu == "read_torque":
		return_data = rospy.get_param("/motor_"+motor_id+"_torque", "-1")

	elif veri_turu == "write_torque":
		rospy.set_param("/motor_"+motor_id+"_torque", int(komut))
		return_data = "OK"

	res = MotorBoostResponse()
	res.out_data = str(return_data)

	print "Motor ID: " + motor_id + " - Sorgu: " + veri_turu + " - Sonuc: " + str(return_data)

	return res



def callbackMotor(data):
	global motor_data
	motor_data = data



def start_server():
    rospy.init_node('node_motor_service_server')

    rospy.Subscriber("motorIncomingData", MotorInArray, callbackMotor)

    s = rospy.Service('server_motor_boost', MotorBoost, handle_service)
    
    print "READY: Motor Service Server"
    
    rospy.spin()

if __name__ == "__main__":
    start_server()