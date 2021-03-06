#!/usr/bin/env python

import rospy
from projectx.srv import *
from projectx.msg import *

def handle_service(req):
	global motor_data, pubSingle, rate
	parseList = req.in_data.split(":")
	veri_turu = parseList[0]
	motor_id = parseList[1]
	komut = parseList[2]

	if veri_turu == "read_present_pos":
		list_sira = int(motor_id)-1
		return_data = motor_data.pos[list_sira]

	elif veri_turu == "read_goal_pos":
		list_sira = int(motor_id)-1
		return_data = motor_data.pos[list_sira]

	elif veri_turu == "read_torque":
		return_data = rospy.get_param("/motor_"+motor_id+"_torque", "0")

	elif veri_turu == "write_torque":

		# AKTARMA

		rospy.set_param("/motor_"+motor_id+"_torque", int(komut))

		data = MotorOut()

		data.id = int(motor_id)
		data.torque = int(komut)

		pubSingle.publish(data)
		rate.sleep()
		return_data = 0 # Geri Donen Veri Yok

	elif veri_turu == "write_goal_pos":

		# IPTAL

		data = MotorOut()

		data.id = int(motor_id)
		data.pos = int(komut)
		data.speed = 0
		data.torque = int(rospy.get_param("/motor_"+motor_id+"_torque", "0"))
		data.rw = 0
		data.action = 0

		print "Service Server - WRITE GOAL ID: "+str(motor_id)+" - POS: "+str(komut)

		pubSingle.publish(data)
		rate.sleep()
		return_data = 0 # Geri Donen Veri Yok


	# BOOST Char Array Icin 4 haneye tamamla (0000)
	basamakla = int(return_data)
	son_return = ""
	if basamakla < 10:
		son_return = "000" + str(return_data)
	elif basamakla < 100:
		son_return = "00" + str(return_data)
	else:
		son_return = "0" + str(return_data)

	res = MotorBoostResponse()
	res.out_data = str(son_return)

	# print "Motor ID: " + motor_id + " - Sorgu: " + veri_turu + " - Komut: " + str(komut) +" - Sonuc: " + str(son_return)

	return res



def callbackMotor(data):
	global motor_data
	# rospy.loginfo(data)
	motor_data = data



def start_server():
    rospy.init_node('node_motor_service_server')

    global pubSingle, rate
    
    pubSingle = rospy.Publisher('motor_out_torque', MotorOut, queue_size=100)

    rospy.Subscriber("motorIncomingData", MotorInArray, callbackMotor)

    s = rospy.Service('server_motor_boost', MotorBoost, handle_service)
    
    rate = rospy.Rate(20)

    rospy.loginfo("READY: Motor Service Server")
    
    rospy.spin()

if __name__ == "__main__":
    start_server()