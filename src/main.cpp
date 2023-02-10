#include <Arduino.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <Bounce2.h>
#define green1 33
#define ldr1 26
#define ldr2 27
//#define lazer1 25
//#define lazer2 14
#define red1 32
#define buzzer1 18

//#define buzzer 8 
//void get
// void PW1(){
//   //รับ powerbank status ตัวแปรสักอัน
//   //if #borrow
//   if (analogRead(ldr1)<4095){
//     analogWrite(green1,1);
//     //post avaliable
//   }
//   else {
//     analogWrite(green1,0);
//     analogWrite(red1,1);
//     //post not avaliable
//   }
//   //else #get not borrow
//   if (analogRead(ldr1)==4095){
//     digitalWrite(buzzer1, HIGH);
//     //post not avalible
//   }
// }
int val;

void setup() {
  Serial.begin(9600);
  pinMode(green1, OUTPUT);
  digitalWrite(green1, 1);
  pinMode(green1, OUTPUT);
  digitalWrite(red1, 1);
  pinMode(red1, OUTPUT);
  pinMode(redpin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  Serial.begin(115200);
  pinMode(buzzer1,OUTPUT);
  //red1.setColor(0,1);
  
}

void loop() {
  // Serial.println(analogRead(ldr2));
  // delay(100);
  // //touch_2();

}