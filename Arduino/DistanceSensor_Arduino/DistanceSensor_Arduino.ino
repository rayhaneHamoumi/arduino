//www.elegoo.com
//2016.12.08
#include "SR04.h"
#define TRIG_PIN 9
#define ECHO_PIN 10
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;

void setup() {
   Serial.begin(9600);
   delay(5000);
}

void loop() {
   a=sr04.Distance();
   Serial.println(a);
   delay(5000);
}
