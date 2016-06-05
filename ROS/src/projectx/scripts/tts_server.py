#!/usr/bin/env python
import rospy
from projectx.msg import *
from projectx.srv import *
from std_msgs.msg import *
import subprocess
import time
import thread
import threading


class My_Thread(threading.Thread):

    def __init__(self,cumle):
        threading.Thread.__init__(self)
        self.process = None

        self.kalinlik = str(rospy.get_param("/tts_server/tts_kalinlik", "40"))
        self.hiz = str(rospy.get_param("/tts_server/tts_hiz", "160"))
        
        self.cumle = cumle
        self.playing = 0

    def run(self):
        self.playing = 1
        cmd = [ "espeak", "-vtr", "-p"+self.kalinlik, "-s"+self.hiz, self.cumle]
        self.process = p = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
        time.sleep(2)
        p.wait()
        self.playing = 0

    def is_play(self):
        return self.playing

    def stop(self):
        if self.process is not None:
            try:
                self.process.terminate()
                self.process = None
            except:
                pass





# Main Subscriber
def tts_callback(req):
    global liste, thr

    komut = req.data
    
    if komut[:3] == "add":
        rospy.loginfo("Eklenecek Cumle: "+ str(komut[4:]))
        liste.append(str(komut[4:]))


    elif komut[:3] == "say":
        rospy.loginfo("Hemen Soylenecek Cumle: "+ str(komut[4:]))
        liste = list()
        thr.stop()
        time.sleep(3) # Bekleme Suresi 2
        say(str(komut[4:]))





def say(cumle):
    global thr, delay_time
    #print "START"
    thr = My_Thread(cumle)
    thr.start()

    # Bitmesini bekle
    while thr.is_play():
        pass

    #print "END"
    thr.stop()
    time.sleep(delay_time)



def main():
    global rate, liste, delay_time

    rospy.Subscriber("service_tts", String, tts_callback)
    
    liste = list()

    time.sleep(8)

    delay_time = rospy.get_param("/tts_server/tts_delay", 6) # Cumleler arasindaki bekleme suresi

    rospy.init_node('tts_server', anonymous=True)
    rate = rospy.Rate(100)

    rospy.loginfo("READY: Text To Speech Server")

    liste.append("Sistem baslatIlIyor") # Bilgi icin konusma

    while not rospy.is_shutdown():
        sessiz = rospy.get_param("/tts_server/tts_quiet", 0)

        boyut = len(liste)
        if boyut > 0:
            if sessiz == 0:
                try:
                    say(liste[0])
                    del(liste[0])
                except:
                    pass

    rospy.spin()



if __name__ == '__main__':
    try:
        main()
    except rospy.ROSInterruptException:
        pass