#!/usr/bin/env python

import rospy
import time
import thread
from projectx.srv import *
from projectx.msg import *


class MyProcess:

    def update_cumle(self, yeni_cumle):
        self.cumle = yeni_cumle


    def spin(self, cumle):
        parsed = cumle.split(" ")

        rospy.loginfo("dyioalog %d",self.diyalog)


        # KONUSMA YENI BASLIYOR
        if self.running == 0:

            self.baslangic(parsed) # Anahtar kelime ara
            
            if self.anahtar_baslangic == 1: # Baslangic olarak anahtar kelime varsa
                self.diyalog = 1
                self.cumle = "" # Cumleyi sifirla
                for i in range(self.index_cumle, int(len(parsed))):
                    self.cumle += parsed[i] + " " # Cumleyi yenile

            if self.diyalog == 1: # Diyalog devam ediyorsa
                self.running = 1
                self.cumle = cumle

        
        # KONUSMA DEVAM EDIYOR
        else:

            if self.anahtar_baslangic == 0:
                self.cumle = cumle # Cumleyi oldugu gibi yenile
            else:
                self.cumle = ""
                for i in range(self.index_cumle, int(len(parsed))):
                    self.cumle += parsed[i] + " " # Cumleyi yenile

            # BITMEYI KONTROL ET
            self.bitis(parsed) # Anahtar kelime ara



    def baslangic(self, parsed):
        # Anahtar kelimenin cumledeki sirasini bul

        # TODO: Kelimeleri db'den cek
        anahtar_giris = ["tesla","robomental","hey","oldu"]

        for i in parsed:
            for a in anahtar_giris:
                if i.lower() == a:
                    try:
                        rospy.loginfo("Baslangic kelimesi bulundu")
                        self.running = 1
                        self.index_cumle = parsed.index(a)
                        self.anahtar_baslangic = 1
                        return 1
                    except:
                        pass


    def bitis(self, parsed):
        # Anahtar kelimenin cumledeki sirasini bul

        # TODO: Kelimeleri db'den cek
        anahtar_giris = ["tamam","ok"]

        for i in parsed:
            for a in anahtar_giris:
                if i.lower() == a:
                    try:
                        self.running = 1
                        self.anahtar_bitis = 1
                        self.index_cumle_bitis = parsed.index(a)
                        rospy.loginfo("Bitti (Anahtar Kelime) %s", self.cumle)
                        self.sifirla()
                        return 1
                    except:
                        pass


    def __init__(self):
        # TIME
        self.timeout = 0 # Kisa timeoutlar icin
        self.gecen_zaman = 0 # Iki cumle akisi arasindaki zaman

        # CUMLE
        self.eski_cumle = "" # Bir onceki cumle
        self.cumle = "" # Mevcut cumle
        self.running = 0 # Robot dinliyor mu
        self.index_cumle = 0 # Baslangic kelimesi varsa kacinci
        self.index_cumle_bitis = 0 # Bitis kelimesi varsa kacinci
        self.anahtar_baslangic = 0 # Baslangic kelimesi var mý
        self.anahtar_bitis = 0 # Bitis kelimesi var mý
        self.diyalog = 0 # Diyalog var mi (uzun konusmalarda anahtar kelimeye ihtiyac duymamak icin)


    def sifirla(self):
        self.timeout = 0
        self.gecen_zaman = 0
        self.cumle = ""
        self.running = 0
        self.index_cumle = 0
        self.index_cumle_bitis = 0
        self.anahtar_baslangic = 0
        self.anahtar_bitis = 0


    def check(self, data):

        if self.timeout == 0:
            # Baslangic
            self.timer = time.time() # Gelen iki veri arasindaki sure
            self.timeout_start() # Veri gelisi uzarsa sureci durdur
            self.timeout = 1
            thread.start_new_thread( self.timeout_short, ("Thread-Timeout", ) ) # Timeout Function
            thread.start_new_thread( self.timeout_diyalog, ("Thread-Timeout-Diyalog", ) ) # Timeout Diyalog Function
        else:
            # Trip
            self.gecen_zaman = time.time() - self.timer # Pes pese gelen veriler arasindaki sure (Kullanilmiyor)
            self.timer = time.time() # Pes pese gelen veriler icin timer'i sifirla
            self.timeout_start() # Timeout icin timer'i sifirla
        
        self.spin(data)

        

    def timeout_start(self):
        self.timout_timer = time.time()

    def timeout_short(self, threadName):
        while True:
            gecen_zaman = time.time() - self.timout_timer
            if gecen_zaman > 2:
                print "timeout: " + str(gecen_zaman)
                rospy.loginfo("Bitti (Timeout) %s", self.cumle)
                self.sifirla()
                break

    def timeout_diyalog(self, threadName):
        while True:
            gecen_zaman = time.time() - self.timout_timer
            if gecen_zaman > 60 * 5: # 5 DK
                print "diyalog timeout: " + str(gecen_zaman)
                rospy.loginfo("Diyalog Bitti %s", self.cumle)
                self.diyalog = 0
                break


    def get_running(self):
        return self.timeout







def handle_service(req):
    global mytimer, myprocess
    data = req.data
    rospy.loginfo(data)

    myprocess.check(data)

    gonder = SpeechResponse()
    gonder.dondur = "OK"
    return gonder



def start_server():
    global myprocess
    rospy.init_node('speech_incoming')
    s = rospy.Service('/service_speech_data', Speech, handle_service)
    rate = rospy.Rate(20)

    myprocess = MyProcess()

    rospy.loginfo("READY: Speech Incoming Server")
    rospy.spin()


if __name__ == "__main__":
    start_server()
