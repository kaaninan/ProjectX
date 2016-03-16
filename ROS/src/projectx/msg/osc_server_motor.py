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
        talker_single(int(name[5:]), value, -1)


    def callback_push(self,data):
        name = data.common.name
        value = data.value
        
        if name == "push1":
            # READ
            pass
        elif name == "push2":
            # SAVE
            pass

        rostopic pub  touchosc_msgs/XYPad '{x: 0.5, y: 0.5}'
    
    
    def listener(self):

        for sayfa_id in range(0,2):
            taslak = "touchosc/"
            taslak += str(sayfa_id)
            taslak += "/fader"
            
            for number in range(0,11):
                taslak1 = taslak + `number`
                rospy.Subscriber(taslak1, ScalableControl, self.callback_fader)
        
        rospy.Subscriber("touchosc/1/push1", ScalableControl, self.callback_push)
        rospy.Subscriber("touchosc/1/push2", ScalableControl, self.callback_push)
        rospy.Subscriber("touchosc/2/push1", ScalableControl, self.callback_push)
        rospy.Subscriber("touchosc/2/push2", ScalableControl, self.callback_push)

        rospy.Subscriber("touchosc/1/multipush1", ScalableControl, self.callback_multipush)
        rospy.Subscriber("touchosc/2/multipush1", ScalableControl, self.callback_multipush)

        rospy.loginfo("OSC: Ready")
        rospy.spin()
    
    
    def __init__(self):
        rospy.init_node('osc_incoming', anonymous=True)
            
        pubSingle = rospy.Publisher('motor_out_torque', MotorOut, queue_size=100)

        for i in range(1,11):
            pub_fader[i] = rospy.Publisher('/touchosc/1/fader'+str(i), ScalableControl, queue_size=100)

        for a in range(1,11):
            pub_fader[10+a] = rospy.Publisher('/touchosc/2/fader'+str(a), ScalableControl, queue_size=100)

        for a in range(1,11):
            label[a] = rospy.Publisher('/touchosc/1/label'+str(a), ScalableControl, queue_size=100)

        for a in range(1,11):
            label[10+a] = rospy.Publisher('/touchosc/2/label'+str(a), ScalableControl, queue_size=100)


        rate = rospy.Rate(100)

        self.listener()






if __name__ == '__main__':
    PublisherData()
