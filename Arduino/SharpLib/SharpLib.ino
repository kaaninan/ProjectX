#include <SharpIR.h>

SharpIR sharp_sag_on(A4, 25, 93, 1080);

void setup(){
//  analogReferance(DEFAULT);
  Serial.begin(9600);
}

void loop(){
  int dis_sag_on = sharp_sag_on.distance();
  
  Serial.print("Kizilotesi: ");
  Serial.println(dis_sag_on);
  
  delay(100);
}
  

