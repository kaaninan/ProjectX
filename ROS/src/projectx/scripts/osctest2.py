#!/usr/bin/env python
import rospy
from projectx.msg import *


class PublisherData:
    
    def talker(self,id,value):
        
        if id < 6:
            id2 = id + 5
        
            motor_data = Motor()
            motor_data.id = id
            motor_data.value = int(value)
            motor_data.hiz = 50
        
            motor_data2 = Motor()
            motor_data2.id = id2
            motor_data2.value = int(value)
            motor_data2.hiz = 50

            self.pub.publish(motor_data)
            self.pub.publish(motor_data2)

        if id == 6:
            
            motor_data = Motor()
            motor_data.id = 11
            motor_data.value = int(value)
            motor_data.hiz = 50
            
            motor_data2 = Motor()
            motor_data2.id = 12
            motor_data2.value = int(value)
            motor_data2.hiz = 50
            
            self.pub.publish(motor_data)
            self.pub.publish(motor_data2)
                    
    
    
    def callback(self,data):
        name = data.common.name
        value = data.value
        
        if name[:4] == "push":
            rospy.loginfo("Push Message: "+name)
        else:
            self.talker(int(name[5:]),value)
            rospy.loginfo(name[5:])
            rospy.loginfo(value)
        
        
        
    
    
    def listener(self):

        for sayfa_id in range(0,6):
            taslak = "touchosc/"
            taslak += str(sayfa_id)
            taslak += "/fader"
            
            push = "touchosc/"
            push += str(sayfa_id)
            push += "/push"
            for number in range(0,21):
                taslak1 = taslak + `number`
                push1 = push + `number`
                rospy.Subscriber(taslak1, ScalableControl, self.callback)
                rospy.Subscriber(push1, ScalableControl, self.callback)
        
        rospy.loginfo("OSC: Ready")
        rospy.spin()
    
    
    def __init__(self):
        rospy.init_node('osc_incoming', anonymous=True)
        #self.pub = rospy.Publisher('hardware_motor_data', Motor, queue_size = 10)
        self.listener()






if __name__ == '__main__':
    PublisherData()
