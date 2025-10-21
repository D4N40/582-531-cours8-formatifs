#include <Arduino.h>
#include <MicroOscSlip.h>
#include <M5_PbHub.h>

M5_PbHub myPbHub;
MicroOscSlip<128> monOsc(&Serial);

#define ANGLE_CHANNEL 0
#define LIGHT_CHANNEL 1

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Wire.begin();
  myPbHub.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  int maLectureAngle = myPbHub.analogRead( ANGLE_CHANNEL);
  int maLectureLight = myPbHub.analogRead( LIGHT_CHANNEL );
  monOsc.sendInt( "/angle" , maLectureAngle);
  monOsc.sendInt( "/light" , maLectureLight);

  delay(100);
}

