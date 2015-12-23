#!/usr/bin/env python

import simplejson as json
from projectx.srv import *
import rospy

## Arduinp Pin Server
# pinMode() ve sensör pinlerini bulmak için kodlanmıştır.

# Pin Listesi (JSON)
json_load = open("pin_list.json")
json_file = json_load.read()

# Liste Parse İşlemleri
def json_parse(istek):
    
    # Tanımlı Kelimeler: input, output, analog
    # Kelimelere uyan tüm pinler array olarak döndürülür
    
    # Pin ismi sorgulanırsa sadece sorgulanan pin numarası döndürülür
    
    if istek == "input":
        try:
            decoded = json.loads(json_file)

            one = decoded['digital']['input']
            two = decoded['pwm']['input']

            pins = list()

            for a in one:
                pins.append(one[a])

            for b in two:
                pins.append(two[b])

        except (ValueError, KeyError, TypeError):
            print "HATA"
    
    elif istek == "output":
        try:
            decoded = json.loads(json_file)

            one = decoded['digital']['output']
            two = decoded['pwm']['output']

            pins = list()

            for a in one:
                pins.append(one[a])

            for b in two:
                pins.append(two[b])

        except (ValueError, KeyError, TypeError):
            print "HATA"
            
    elif istek == "analog":
        try:
            decoded = json.loads(json_file)

            one = decoded['analog']

            pins = list()

            for a in one:
                pins.append(one[a])

        except (ValueError, KeyError, TypeError):
            print "HATA"
            
    else:
        try:
            decoded = json.loads(json_file)

            one = decoded['digital']['input']
            two = decoded['digital']['output']
            three = decoded['analog']
            four = decoded['pwm']['input']
            five = decoded['pwm']['output']

            pins = list()

            for a in one:
                if a == istek:
                    pins.append(one[a])
                    
            for a in two:
                if a == istek:
                    pins.append(two[a])
                    
            for a in three:
                if a == istek:
                    pins.append(three[a])
                    
            for a in four:
                if a == istek:
                    pins.append(four[a])
                    
            for a in five:
                if a == istek:
                    pins.append(five[a])

        except (ValueError, KeyError, TypeError):
            print "HATA"
        
    # Array Kontrolu
    
    if len(pins) != 0:
        return pins
    else:
        return -1
        
        
        
        
        
        
def handle_pin(req):
    donut = json_parse(req.name)
	print "Call Pin Service"
    rospy.loginfo("Call Pin Service")
	return PinResponse(donut)

def pin_server():
	rospy.init_node('node_pin_server')
	s = rospy.Service('arduino_pin_service', Pin, handle_pin)
	print "Ready Arduino Pin Service"
    rospy.loginfo("Ready Arduino Pin Service")
	rospy.spin()
	
if __name__ == "__main__":
	pin_server()