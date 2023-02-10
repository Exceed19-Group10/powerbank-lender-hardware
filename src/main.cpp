#include <Arduino.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#define green1 33
#define ldr1 26
#define ldr2 27
#define red1 32
#define buzzer1 18
#define Borrow_mai 0

void pw1(){
  if (Borrow_mai){
      digitalWrite(green1,1);
      if (analogRead(ldr1)>=3900){
        digitalWrite(green1,0);
        digitalWrite(red1,1);
      }
      else  {
        digitalWrite(green1,1);
        digitalWrite(red1,0);
      }
  }
  else{
   
    if(analogRead(ldr1)>=3900){
      digitalWrite(red1,1);
      digitalWrite(buzzer1, HIGH);
      pai_laew(PB_ID);
    }
    else{
      digitalWrite(buzzer1, LOW);
      digitalWrite(red1,0);
    }
  
  }
}

void kuen(){
if(analogRead(ldr1)<4095){
  digitalWrite(green1,1);
  return_laew(PB_ID);
}
}




void setup() {
  Serial.begin(9600);
  pinMode(green1, OUTPUT);
  digitalWrite(green1, 0);
  pinMode(green1, OUTPUT);
  digitalWrite(red1, 0);
  pinMode(red1, OUTPUT);
  pinMode(red1, OUTPUT);
  pinMode(green1, OUTPUT);
  Serial.begin(115200);
  pinMode(buzzer1,OUTPUT);
  
}

void loop() {
pw1();
Serial.println(analogRead(ldr1));
kuen();
}