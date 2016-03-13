#include <DynamixelSerial1.h>

void setup() {
  Dynamixel.begin(1000000, 2); // Inicialize the servo at 1Mbps and Pin Control 2
  Serial.begin(9600);
  delay(500);
}

void loop() {

  for (int i = 1; i < 21; i++) {
    Dynamixel.ledStatus(i, OFF);
    delay(100);

    Dynamixel.setTempLimit(i, 100); // Set Max Temperature to 80 Celcius
    delay(10);
    Dynamixel.setVoltageLimit(i, 65, 160); // Set Operating Voltage from 6.5v to 16v
    delay(10);
    Dynamixel.setCSlope(i, 1, 1); // Set Operating Voltage from 6.5v to 16v
    delay(10);
    Dynamixel.setMaxTorque(i, 1000);       // 50% of Torque
    delay(10);
    Dynamixel.setSRL(i, 2);               // Set the SRL to Return All
    delay(10);


    Dynamixel.ledStatus(i, ON);          // Turn ON the LED

    Serial.print(i);
    Serial.println(" -> FINISH");

    delay(100);
  }

  while(1){}

}
