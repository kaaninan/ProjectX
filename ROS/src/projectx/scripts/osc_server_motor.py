#!/usr/bin/env python
import rospy
from projectx.msg import *


class PublisherData:
    
    def talker_single(self,id,pos,torque):
        data = MotorOut()

        data.id = id
        data.pos = value
        data.torque = torque

        pubSingle.publish(data)
        rate.sleep()
                    
    
    
    def callback_fader(self,data):
        name = data.common.name
        value = data.value
        rospy.loginfo(str(name)+" -> "+str(value))
        #talker_single(int(name[5:]), value, -1)


    def callback_multipush(self,data):
        pass
        

    
    def listener(self):

        for sayfa_id in range(0,2):
            taslak = "touchosc/"
            taslak += str(sayfa_id)
            taslak += "/fader"
            
            for number in range(0,11):
                taslak1 = taslak + `number`
                rospy.Subscriber(taslak1, ScalableControl, self.callback_fader)

        rospy.Subscriber("touchosc/1/multipush1", ScalableControl, self.callback_multipush)
        rospy.Subscriber("touchosc/2/multipush1", ScalableControl, self.callback_multipush)

        rospy.loginfo("OSC MOTOR: Ready")
        rospy.spin()
    
    
    def __init__(self):
        rospy.init_node('osc_incoming', anonymous=True)
        
        pubSingle = rospy.Publisher('motor_out_single', MotorOut, queue_size=100)

        rate = rospy.Rate(100)

        self.listener()






if __name__ == '__main__':
    PublisherData()
