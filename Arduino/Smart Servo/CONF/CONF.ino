#include <DynamixelSerial1.h>

void setup() {
  Dynamixel.begin(1000000, 2); // Inicialize the servo at 1Mbps and Pin Control 2
  Serial.begin(9600);
  delay(2000);
}

void loop() {

  for (int i = 1; i < 21; i++) {
    Dynamixel.ledStatus(i, OFF);
    Dynamixel.move(i, random(500, 550)); // Move the Servo radomly from 200 to 800
    delay(1000);

    Dynamixel.setTempLimit(i, 80); // Set Max Temperature to 80 Celcius
    Dynamixel.setVoltageLimit(i, 65, 160); // Set Operating Voltage from 6.5v to 16v
    Dynamixel.setCSlope(i, 32, 32); // Set Operating Voltage from 6.5v to 16v
    Dynamixel.setMaxTorque(i, 1000);       // 50% of Torque
    Dynamixel.setSRL(i, 2);               // Set the SRL to Return All

    Dynamixel.ledStatus(i, ON);          // Turn ON the LED

    Serial.print(i);
    Serial.println(" -> FINISH");

    delay(1000);
  }

  while(1){}

}
