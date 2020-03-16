#include <IRremote.h>
#define echoPin 7
#define trigPin 8
#define buzzer 5
#include <Wire.h>
#include <DS1307.h>
#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 10
#define RST_PIN 9

long duration;
long distance,d2;
DS1307 rtc;
int chng=0;
IRsend irsend;
MFRC522 rfid(SS_PIN, RST_PIN);
MFRC522::MIFARE_Key key;
byte nuidPICC[4];
long iii=0;
long f,ii;
long slidevalue,limit;
uint8_t rf_min=61;
uint8_t rf_hour=25;
uint8_t rf_sec,rf_day,rf_month;
uint16_t rf_year;
int accepted=0;

void setup() {
  Serial.begin(9600);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(buzzer, OUTPUT);
  rtc.start();
  SPI.begin(); // Init SPI bus
  rfid.PCD_Init(); // Init MFRC522 

  for (byte i = 0; i < 6; i++) {
    key.keyByte[i] = 0xFF;
  }
}


void printDec(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], DEC);
  }
}


void loop() {
   //RFID
   
  
  //TIMER
  uint8_t sec, min, hour, day, month;
  uint16_t year;
  rtc.get(&sec, &min, &hour, &day, &month, &year);
  if(hour>7 && hour<10){
    if(min==55 && sec<5){
      digitalWrite(buzzer,HIGH);
      delay(700);
      }}
  if(hour>10 && hour<13){
    if(min==25 && sec<5){
      digitalWrite(buzzer,HIGH);
      delay(700);
      }}
  if(hour>13 && hour<16){
    if(min==10 && sec<5){
      digitalWrite(buzzer,HIGH);
      delay(700);
      }}
  
 
  digitalWrite(buzzer,LOW);
  if(hour==14 && min==11 && sec<5)
  {
    Serial.print("AISH");
    digitalWrite(buzzer,HIGH);
    delay(700);
    }
    digitalWrite(buzzer,LOW);
   //TIMER

if ( ! rfid.PICC_IsNewCardPresent())
    return;
  // Verify if the NUID has been readed
  if ( ! rfid.PICC_ReadCardSerial())
    return;
    
   for (byte i = 0; i < 4; i++) {
      nuidPICC[i] = rfid.uid.uidByte[i];
    }
    printDec(rfid.uid.uidByte, rfid.uid.size);
    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();
    if ((rfid.uid.uidByte[0] == 217 || rfid.uid.uidByte[0] == 23) || 
    (rfid.uid.uidByte[1] == 252 || rfid.uid.uidByte[1] == 115)  || 
    (rfid.uid.uidByte[2] == 243 || rfid.uid.uidByte[2] == 150) || 
    (rfid.uid.uidByte[3] == 151 || rfid.uid.uidByte[3] == 86) ) 
    {
      accepted=1;
        rtc.get(&rf_sec, &rf_min, &rf_hour, &rf_day, &rf_month, &rf_year);
    }
    limit=rf_hour*60+rf_min+2;
    if(hour*60+min>limit && accepted==1)
    {
      Serial.println("deny");
      accepted=0;
    }
    while(hour*60+min<limit && accepted==1)
    {
rtc.get(&sec, &min, &hour, &day, &month, &year);

    
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  
  digitalWrite(trigPin,LOW);
  duration = pulseIn(echoPin,HIGH);
  distance=duration/58.2;


  
  if(distance > 0 && distance < 20)
  {
    digitalWrite(buzzer,HIGH);
    irsend.sendNEC(0x4CB3817E, 32);
    Serial.println("POWER");
    Serial.println(distance);
    Serial.println("         ");
    delayMicroseconds(1000);
  }
  

 
  if(distance > 20 && distance < 30)
  {
    digitalWrite(buzzer,HIGH);
    irsend.sendNEC(0x4CB311EE, 32);
    digitalWrite(buzzer,LOW);
    delay(300);
    irsend.sendNEC(0x4CB3936C, 32);
    delay(300);
    irsend.sendNEC(0x4CB3E31C, 32);
    delay(300);
    irsend.sendNEC(0x4CB3E31C, 32);
    delay(300);
    irsend.sendNEC(0x4CB3936C, 32);
    delay(300);
    irsend.sendNEC(0x4CB313EC, 32);
    delay(300);
    irsend.sendNEC(0x4CB311EE, 32);
    delay(300);
    irsend.sendNEC(0x4CB311EE, 32);
    delay(300);
    irsend.sendNEC(0x4CB311EE, 32);
    Serial.println("4:3");
    Serial.println(distance);
    Serial.println("         ");
    delayMicroseconds(1000);
  }


  if(distance > 30 && distance < 38)
  {
    digitalWrite(buzzer,HIGH);
    irsend.sendNEC(0x4CB3639C, 32);
    Serial.println("UP");
    Serial.println(distance);
    Serial.println("         ");
    delayMicroseconds(1000);
  }

  if(distance > 38 && distance < 46)
  {
    digitalWrite(buzzer,HIGH);
    irsend.sendNEC(0x4CB3E31C, 32);
    Serial.println("Down");
    Serial.println(distance);
    Serial.println("         ");
    delayMicroseconds(1000);
  }



  if(distance > 46 && distance < 54)
  {
    digitalWrite(buzzer,HIGH);
    irsend.sendNEC(0x4CB3936C, 32);
    Serial.println("right");
    Serial.println(distance);
    Serial.println("         ");
    delayMicroseconds(1000);
  }



  if(distance > 54 && distance < 62)
  {
    digitalWrite(buzzer,HIGH);
    irsend.sendNEC(0x4CB313EC , 32);
    Serial.println("Left");
    Serial.println(distance);
    Serial.println("         ");
    delayMicroseconds(1000);
  }

  if(distance > 62 && distance < 82)
  {
    digitalWrite(buzzer,HIGH);
    irsend.sendNEC(0x4CB311EE, 32);
    Serial.println("Menu");
    Serial.println(distance);
    Serial.println("         ");
    delayMicroseconds(1000);
  } 

  if(distance > 82 && distance < 92)
  {
    digitalWrite(buzzer,HIGH);
    irsend.sendNEC(0x4CB311EE, 32);
    digitalWrite(buzzer,LOW);
    delay(300);
    irsend.sendNEC(0x4CB3936C, 32);
    delay(300);
    irsend.sendNEC(0x4CB3E31C, 32);
    delay(300);
    irsend.sendNEC(0x4CB3E31C, 32);
    delay(300);
    irsend.sendNEC(0x4CB3936C, 32);
    delay(300);
    irsend.sendNEC(0x4CB3936C, 32);
    delay(300);
    irsend.sendNEC(0x4CB311EE, 32);
    delay(300);
    irsend.sendNEC(0x4CB311EE, 32);
    delay(300);
    irsend.sendNEC(0x4CB311EE, 32);
    Serial.println("16:9");
    Serial.println(distance);
    Serial.println("         ");
    delayMicroseconds(1000);
  } 

  if(distance > 92 && distance < 102)
  {
    digitalWrite(buzzer,HIGH);
    irsend.sendNEC(0x4CB353AC, 32);
    Serial.println("Ok");
    Serial.println(distance);
    Serial.println("         ");
    delayMicroseconds(1000);
  }  
  digitalWrite(buzzer,LOW);
  //Serial.println(distance);
  delay(500); } 
}
