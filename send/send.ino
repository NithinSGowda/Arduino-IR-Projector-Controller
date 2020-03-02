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

  if(distance > 5 && distance < 10)
  {
    digitalWrite(buzzer,HIGH);
    irsend.sendNEC(0x4CB311EE, 32);
    Serial.println("Menu");
    Serial.println(distance);
    Serial.println("         ");
    delayMicroseconds(1000);
  }

  
  if(distance > 10 && distance < 15)
  {
    digitalWrite(buzzer,HIGH);
    irsend.sendNEC(0x4CB3817E, 32);
    Serial.println("POWER");
    Serial.println(distance);
    Serial.println("         ");
    delayMicroseconds(1000);
  }


  if(distance > 15 && distance < 20)
  {
    digitalWrite(buzzer,HIGH);
    irsend.sendNEC(0x4CB353AC, 32);
    Serial.println("Ok");
    Serial.println(distance);
    Serial.println("         ");
    delayMicroseconds(1000);
  }



  if(distance > 20 && distance < 25)
  {
    digitalWrite(buzzer,HIGH);
    irsend.sendNEC(0x4CB3639C, 32);
    Serial.println("Up");
    Serial.println(distance);
    Serial.println("         ");
    delayMicroseconds(1000);
  }



  if(distance > 25 && distance < 30)
  {
    digitalWrite(buzzer,HIGH);
    irsend.sendNEC(0x4CB3E31C, 32);
    Serial.println("Down");
    Serial.println(distance);
    Serial.println("         ");
    delayMicroseconds(1000);
  }



  if(distance > 30 && distance < 35)
  {
    digitalWrite(buzzer,HIGH);
    irsend.sendNEC(0x4CB3936C, 32);
    Serial.println("right");
    Serial.println(distance);
    Serial.println("         ");
    delayMicroseconds(1000);
  }



  if(distance > 35 && distance < 40)
  {
    digitalWrite(buzzer,HIGH);
    irsend.sendNEC(0x4CB313EC , 32);
    Serial.println("Left");
    Serial.println(distance);
    Serial.println("         ");
    delayMicroseconds(1000);
  }




  if(distance > 40 && distance < 45)
  {
    digitalWrite(buzzer,HIGH);
    
    irsend.sendNEC(0x4CB311EE, 32);
    delay(300);
    irsend.sendNEC(0x4CB3936C, 32);
    delay(300);
    irsend.sendNEC(0x4CB3936C , 32);
    delay(300);
    irsend.sendNEC(0x4CB3E31C , 32);
    delay(300);
    irsend.sendNEC(0x4CB3E31C , 32);
    delay(300);
    irsend.sendNEC(0x4CB3936C , 32);
    
    Serial.println("Brightness");
    Serial.println(distance);
    Serial.println("         ");
    delayMicroseconds(1000);
  }



  if(distance > 45 && distance < 50)
  {
    digitalWrite(buzzer,HIGH);
    irsend.sendNEC(0x44CB331CE, 32);
    Serial.println("Volume Up");
    Serial.println(distance);
    Serial.println("         ");
    delayMicroseconds(1000);
  }



  if(distance > 50 && distance < 55)
  {
    digitalWrite(buzzer,HIGH);
    irsend.sendNEC(0x4CB3F10E, 32);
    Serial.println("Volume Down");
    Serial.println(distance);
    Serial.println("         ");
    delayMicroseconds(1000);
  }



  if(distance > 515 && distance < 610)
  {
    digitalWrite(buzzer,HIGH);
    irsend.sendNEC(0x4CB323DC, 32);
    Serial.println("ReSync");
    Serial.println(distance);
    Serial.println("         ");
    delayMicroseconds(1000);
  }

  if(distance > 60 && distance < 65)
  {
    digitalWrite(buzzer,HIGH);
    
    irsend.sendNEC(0x4CB311EE, 32);
    delay(300);
    irsend.sendNEC(0x4CB3936C, 32);
    delay(300);
    irsend.sendNEC(0x4CB3E31C , 32);
    delay(300);
    irsend.sendNEC(0x4CB3E31C , 32);
    delay(300);
    irsend.sendNEC(0x4CB3E31C , 32);
    delay(300);
    irsend.sendNEC(0x4CB3E31C , 32);
    delay(300);
    irsend.sendNEC(0x4CB3936C , 32);
    
    Serial.println("Zoom");
    Serial.println(distance);
    Serial.println("         ");
    delayMicroseconds(1000);
  }

  
  else{
    digitalWrite(buzzer,LOW);
    }
  //Serial.println(distance);

  delay(1000);  
}
