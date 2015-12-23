#!/usr/bin/env python
import rospy
from projectx.msg import ScalableControl
from projectx.msg import MotorOut



class PublisherData:
    
    def talker(self,id,value):
        motor_data = MotorOut()
        motor_data.id = id
        motor_data.pos = int(value)
        motor_data.torque = 1
        motor_data.speed = 0
        motor_data.rw = 0
        motor_data.action = 0
#        rospy.loginfo(motor_data.value[id])
        rospy.loginfo("ok");
        self.pub.publish(motor_data)


    def callback(self,data):
        name = data.common.name
        value = data.value
        
        self.talker(int(name[5:]),value)
        
        rospy.loginfo(name[5:])
        rospy.loginfo(value)


    def listener(self):
        taslak = "touchosc/1/fader"
        for number in range(0,21):
            taslak1 = taslak + `number`
            rospy.Subscriber(taslak1, ScalableControl, self.callback)

        taslak = "touchosc/2/fader"
        for number in range(0,21):
            taslak1 = taslak + `number`
            rospy.Subscriber(taslak1, ScalableControl, self.callback)
        
        rospy.loginfo("ROS OSC Started")
        
        rospy.spin()


    def __init__(self):
        rospy.init_node('osc_pubsub', anonymous=True)
        self.pub = rospy.Publisher('arduinoMotorOutgoing', MotorOut, queue_size = 10)
        self.listener()






if __name__ == '__main__':
    PublisherData()
