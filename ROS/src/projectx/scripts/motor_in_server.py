#!/usr/bin/env python
import rospy
from projectx.msg import *
from std_msgs.msg import *
import thread

motor_values = {}


def dogrula():
    global motor_values
    for i in range(1,21):
        try:
            if int(motor_values[i].get("pos")):
                pass
        # Sorun Yok
        except:
            #rospy.loginfo("motorSubscriber.py -> Arduino'dan gelen motor verileri eksik! (topic: arduinoMotorIncoming) - Motor ID: [%s]",str(i))
            return 0
    rospy.loginfo("motorSubscriber.py -> SERVO MOTOR OK")
    return 1




def publish_data(thread_name,delay):
    global ok_
    global motor_values

    while  1:
        if ok_ == 1:
            motorData = MotorInArray()

            try:
                for i in range(1,21):
                    # motorData.temp.append(int(motor_values[i].get("temp")))
                    # motorData.voltage.append(int(motor_values[i].get("voltage")))
                    motorData.pos.append(int(motor_values[i].get("pos")))
                global pub, rate
                # rospy.loginfo("Motor In Server")
                # rospy.loginfo(motorData)
                pub.publish(motorData)
                rate.sleep()
            except:
                tamam = 0

            




ok_ = -1 # Her Seferinde dogrula() fonk. calismamasi icin

def yazdir():
    global ok_
    
    if ok_ != 1:
        ok_ = dogrula()
        #print "Tum Degerler Dogrulanmadi!"






def deger_bul(id, bolum):
    try:
        if motor_values.get(id)[bolum]:
            return motor_values.get(id)[bolum]
    except:
        return 0


def callback(data):
    
    # rospy.loginfo("%s, %s, %s, %s", data.id, data.temp, data.voltage, data.pos)
    
    
    # Gelen Verinin Dogruluk Kontrolu
    # TECRUBE: Ilk basta tum veriler tam gelene kadar yaklasik 2sn geciyor.
    # Eger gecersiz deger gelirse varolan degeri koru
    
    # if data.temp < 2 or data.temp > 200:
    #     deger = deger_bul(data.id, "temp")
    #     temp_ = deger
    # else:
    #     temp_ = int(data.temp)
    
    
    # if data.voltage < 2 or data.voltage > 200:
    #     deger = deger_bul(data.id, "voltage")
    #     voltage_ = deger
    # else:
    #     voltage_ = int(data.voltage)
    
    
    if data.deger < 1 or data.deger > 1030:
        deger = deger_bul(data.id, "pos")
        pos_ = deger
    else:
        pos_ = int(data.deger)

    
    global motor_values
    motor_values[data.id] = {"pos": pos_}
    yazdir()
    # rospy.loginfo(data)
    # rospy.loginfo(motor_values)


def listener():
    
    rospy.init_node('motor_values_listener', anonymous=True)
    
    rospy.Subscriber("arduino_in_motor", Hash, callback)

    try:
        thread.start_new_thread(publish_data, ("Thread-1",2))
    except:
        rospy.logerr("Thread Error");
    
    global pub, rate
    
    pub = rospy.Publisher('motor_incoming_data', MotorInArray, queue_size=10)
    rate = rospy.Rate(100)

    rospy.loginfo("READY: Motor Incoming Server")
    
    rospy.spin()

if __name__ == '__main__':
    listener()