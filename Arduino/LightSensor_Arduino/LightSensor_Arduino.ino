#define led 13
#define buzzer 6
#define pirSensor 8



void setup() { 
 Serial.begin(9600);
  pinMode(pirSensor, INPUT); 
  pinMode(led,OUTPUT);
  pinMode(buzzer,OUTPUT);
}

void loop() {
  
int x= digitalRead(pirSensor);

  if(x==LOW)
  {
    digitalWrite(led,LOW);
    digitalWrite(buzzer,LOW);
    Serial.println(x);
  }
  else
  {
    digitalWrite(led,HIGH);
    digitalWrite(buzzer,HIGH);
    Serial.println(x);
  }
  delay(5000);
}
