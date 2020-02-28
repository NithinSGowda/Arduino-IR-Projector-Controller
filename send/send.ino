#include <IRremote.h>
#define echoPin 7
#define trigPin 8
#define buzzer 11

long duration;
long distance;

IRsend irsend;

void setup() {
  Serial.begin(9600);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin,LOW);

  duration = pulseIn(echoPin,HIGH);
  distance=duration/58.2;

  if(distance > 10 && distance < 15)
  {
    digitalWrite(buzzer,HIGH);
    irsend.sendNEC(0x4CB3817E, 32); //Power Code
  }
  else{
    digitalWrite(buzzer,LOW);
    }
  Serial.println(distance);

  delay(50);  
}
