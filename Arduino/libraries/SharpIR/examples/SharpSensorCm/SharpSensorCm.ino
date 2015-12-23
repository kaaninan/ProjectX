#include <SharpIR.h>
#include <Servo.h>

SharpIR sharp(A0, 25, 93, 1080);


void setup() {
  Serial.begin(9600);

}

void loop() {

  int dis = sharp.distance();
  Serial.println(dis);
  delay(200);

}


