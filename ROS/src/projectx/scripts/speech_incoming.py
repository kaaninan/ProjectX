#!/usr/bin/env python

import rospy
from projectx.srv import *
from projectx.msg import *

def handle_service(req):
    data = req.data
    rospy.loginfo(data)
    gonder = SpeechResponse()
    gonder.dondur = "OK"
    return gonder



def start_server():
    rospy.init_node('speech_incoming')
    
    s = rospy.Service('/service_speech_data', Speech, handle_service)
    
    rate = rospy.Rate(20)

    rospy.loginfo("READY: Speech Incoming Server")
    
    rospy.spin()

if __name__ == "__main__":
    start_server()


    
# #!/usr/bin/env python
# import rospy
# from projectx.msg import *
# from std_msgs.msg import *


# def callback_speech_data(data):
    
#     if data.data != "ok":
#         rospy.loginfo(data)


# def main():

#     #pub_pos = rospy.Publisher('Amop', IntArray, queue_size=10) # Motor (Position)
    
#     rospy.Subscriber("/speech_data", String, callback_speech_data)

#     rospy.init_node('speech_incoming', anonymous=True)

#     rate = rospy.Rate(100)

#     rospy.loginfo("READY: Speech Incoming Server")
#     rospy.spin()
    

# if __name__ == '__main__':
#     try:
#         main()
#     except rospy.ROSInterruptException:
#         pass