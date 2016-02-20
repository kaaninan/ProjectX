#!/usr/bin/env python

import rospy
import BaseHTTPServer, SimpleHTTPServer
import ssl

def start():

	ip_address = rospy.get_param("/speech_ip_address", "192.168.1.37")
	port = rospy.get_param("/speech_port", 8008)

	httpd = BaseHTTPServer.HTTPServer((ip_address, port), SimpleHTTPServer.SimpleHTTPRequestHandler)
	httpd.socket = ssl.wrap_socket (httpd.socket, certfile='/home/rock/ProjectX/Speak/server.pem', server_side=True)
	httpd.serve_forever()

if __name__ == '__main__':
	rospy.loginfo("STARTED: Speak Server")
	start()