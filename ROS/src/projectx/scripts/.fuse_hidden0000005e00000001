#!/usr/bin/env python
import rospy
from projectx.msg import MotorIn

motor_values = {}


# PARAM Kullanilmiyor -- Cok Yavas


def dogrula():
    global motor_values
    for i in range(1,21):
        try:
            if motor_values[i].get("pos") and motor_values[i].get("temp") and motor_values[i].get("voltage"):
                don = 1 # Bos Durmasin Diye
                # Sorun Yok
        except:
            rospy.logerr("motorSubscriber.py -> Arduino'dan gelen motor verileri eksik! (topic: arduinoMotorIncoming) - Motor ID: [%s]",str(i))
            return 0
    rospy.loginfo("motorSubscriber.py -> SERVO MOTOR OK")
    return 1



ok_ = -1 # Her Seferinde dogrula() fonk. calismamasi icin

def yazdir():
    global motor_values
    global ok_
    
    if ok_ == 1:
        for i in range(1,21):
            # Tum Degerler Dogrulandiginda Surekli Parametre Guncelleniyor
#            print (i, ' ',motor_values[i])

            _name_temp = "/motor_" + str(i) + "/temp"
            _name_volt = "/motor_" + str(i) + "/voltage"
            _name_pos = "/motor_" + str(i) + "/pos"
            
#            try:
#                rospy.set_param(_name_temp, motor_values[i].get("temp"))
#                rospy.set_param(_name_volt, motor_values[i].get("voltage"))
#                rospy.set_param(_name_pos, motor_values[i].get("pos"))
#            except:
#                rospy.logerr("PARAM SET ERROR");

    else:
        ok_ = dogrula()
        #print "Tum Degerler Dogrulanmadi!"






def deger_bul(id, bolum):
    try:
        if motor_values.get(id)[bolum]:
            return motor_values.get(id)[bolum]
    except:
        return 0


def callback(data):
    
    #    rospy.loginfo("%s, %s, %s, %s", data.id, data.temp, data.voltage, data.pos)


    # Gelen Verinin Dogruluk Kontrolu
    # TECRUBE: Ilk basta tum veriler tam gelene kadar yaklasik 2sn geciyor.
    # Eger gecersiz deger gelirse varolan degeri koru
    
    if data.temp < 1 or data.temp > 200:
        deger = deger_bul(data.id, "temp")
        temp_ = deger
    else:
        temp_ = data.temp


    if data.voltage < 1 or data.voltage > 200:
        deger = deger_bul(data.id, "voltage")
        voltage_ = deger
    else:
        voltage_ = data.voltage


    if data.pos < 0 or data.pos > 2000:
        deger = deger_bul(data.id, "pos")
        pos_ = deger
    else:
        pos_ = data.pos


    if data.id == 1:
        print("1 -> ", data.pos, " -- ", pos_);

    global motor_values

    motor_values[data.id] = {"temp":temp_, "voltage":voltage_, "pos": pos_}

    yazdir()


def listener():
    
    rospy.init_node('motor_values_listener', anonymous=True)
    
    rospy.Subscriber("arduinoMotorIncoming", MotorIn, callback)
    
    rospy.spin()

if __name__ == '__main__':
    listener()