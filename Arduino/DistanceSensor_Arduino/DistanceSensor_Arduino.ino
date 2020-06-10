/* import libraries */
#include "SR04.h"
/* De nodige pin definieren van onze arduino */
#define TRIG_PIN 9
#define ECHO_PIN 10
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long dist;

/* begint te schrijven in de console */
void setup() {
   Serial.begin(9600);
}
/* met de 2 pinnen en de librarie geeft hij de distance terug en print deze in de console */
void loop() {
   dist=sr04.Distance();
   Serial.println(dist);
   delay(5000);
}
