/* De nodige pin definieren van onze arduino */
#define led 13
#define buzzer 6
#define pirSensor 8


/* De data van de prisensor is een input deze geeft data terug en led en de buzzer krijegn data wanneer de pirsensor active is */
void setup() { 
 Serial.begin(9600);
  pinMode(pirSensor, INPUT); 
  pinMode(led,OUTPUT);
  pinMode(buzzer,OUTPUT);
}
/* geetf variable detect digitaal weer (0 of 1) wanneer dat het 0 is is het gelijk aan low en als het 1 is gaat de else functie in actie en gaat het licht en de buzzer aan */
void loop() {
  
int detect= digitalRead(pirSensor);

  if(detect==LOW)
  {
    digitalWrite(led,LOW);
    digitalWrite(buzzer,LOW);
    Serial.println(detect);
  }
  else
  {
    digitalWrite(led,HIGH);
    digitalWrite(buzzer,HIGH);
    Serial.println(detect);
  }
  delay(5000);
}
