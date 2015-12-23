#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif
#include <ros.h>
#include <std_msgs/Float64.h>
#include <projectx/Pin.h>
#include <projectx/SensorTemp.h>
#include <projectx/Sensor.h>

#include <OneWire.h>
#include <dht.h>
#include <SharpIR.h>


// ## PIN ##

// # Digital

// Input
const int pin_sicaklik = 22;
const int pin_dht11 = 23;
const int pin_one_wire = 24;
const int pin_hareket_1 = 25;


// Analog
const int pin_sharp_1 = 0;
const int pin_sharp_2 = 1;
const int pin_sharp_3 = 2;
const int pin_alev = 3;



// ## Sensor Pin
OneWire  ds(pin_one_wire);
dht DHT;
SharpIR sharp_1(pin_sharp_1, 25, 93, 1080);
SharpIR sharp_2(pin_sharp_2, 25, 93, 1080);
SharpIR sharp_3(pin_sharp_3, 25, 93, 1080);


ros::NodeHandle nh;
std_msgs::Float64 msg;
projectx::Sensor sensor_data;


void callbackTemp(const projectx::SensorTemp::Request & req, projectx::SensorTemp::Response & res) {
  float temp = sensor_sicaklik();
  float dht_temp = dht11_sicaklik();
  float dht_nem = dht11_nem();
  res.temp1 = temp;
  res.temp2 = dht_temp;
  res.nem = dht_nem;
  digitalWrite(13, HIGH);
}







// Service Server




// SENSOR

// ## One Wire Sicaklik

float sensor_sicaklik() {
  byte i;
  byte present = 0;
  byte type_s;
  byte data[12];
  byte addr[8];
  float celsius, fahrenheit;

  if ( !ds.search(addr)) {
    ds.reset_search();
  }

  ds.reset();
  ds.select(addr);
  ds.write(0x44, 1);

  present = ds.reset();
  ds.select(addr);
  ds.write(0xBE);
  for ( i = 0; i < 9; i++) {
    data[i] = ds.read();
  }
  int16_t raw = (data[1] << 8) | data[0];
  if (type_s) {
    raw = raw << 3;
    if (data[7] == 0x10) {
      raw = (raw & 0xFFF0) + 12 - data[6];
    }
  } else {
    byte cfg = (data[4] & 0x60);
    if (cfg == 0x00) raw = raw & ~7;
    else if (cfg == 0x20) raw = raw & ~3;
    else if (cfg == 0x40) raw = raw & ~1;
  }
  celsius = (float)raw / 16.0;
  return celsius;
}

// ## DHT11 Sicaklik ve Nem

float dht11_sicaklik() {
  DHT.read11(pin_dht11);
  float veri = DHT.temperature;
  return veri;
}

float dht11_nem() {
  DHT.read11(pin_dht11);
  float veri = DHT.humidity;
  return veri;
}

int sensor_sharp() {
  int final = 0;
  int dis = sharp_1.distance();
  if (dis > 80) final = 80;
  else if (dis < 5) final = 5;
  else {
    final = dis;
  }
  return final;
}

int sensor_sharp_2() {
  int final = 0;
  int dis = sharp_2.distance();
  if (dis > 80) final = 80;
  else if (dis < 5) final = 5;
  else {
    final = dis;
  }
  return final;
}

int sensor_sharp_3() {
  int final = 0;
  int dis = sharp_3.distance();
  if (dis > 80) final = 80;
  else if (dis < 5) final = 5;
  else {
    final = dis;
  }
  return final;
}

int sensor_alev() {
  return analogRead(pin_alev);
}

int sensor_hareket() {
  return digitalRead(pin_hareket_1);
}

ros::Publisher p_sensor("topicArduinoSensor", &sensor_data);
ros::ServiceClient<projectx::Pin::Request, projectx::Pin::Response> client("arduino_pin_service");
ros::ServiceServer<projectx::SensorTemp::Request, projectx::SensorTemp::Response> serverTemp("sensor_temp_service", &callbackTemp);


// Service Client

void pinNo() {
  projectx::Pin::Request req;
  projectx::Pin::Response res;
  req.name = "sicaklik";
  client.call(req, res);
}


void manualPinMode() {
  // Digital Input
  pinMode(pin_sicaklik, INPUT);
  pinMode(pin_dht11, INPUT);
  pinMode(pin_one_wire, INPUT);
}

void setup() {
  nh.initNode();
  nh.advertise(p_sensor);
  nh.advertiseService(serverTemp);
  nh.serviceClient(client);

  while (!nh.connected()) nh.spinOnce(); // for Service Wait

  manualPinMode();

  pinNo();
}


void loop() {

  // Send Sensor Data
  sensor_data.sharp1 = sensor_sharp();
  sensor_data.sharp2 = sensor_sharp_2();
  sensor_data.sharp3 = sensor_sharp_3();
  sensor_data.ldr = 23;
  sensor_data.alev = sensor_alev();
  sensor_data.hareket = sensor_hareket();

  p_sensor.publish(&sensor_data);

  nh.spinOnce();
  delay(10); // for Lost Connection
}


