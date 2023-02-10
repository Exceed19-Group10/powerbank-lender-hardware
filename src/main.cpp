#include <Arduino.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <iostream>

#define green1 33
#define ldr1 26
#define ldr2 27
#define red1 32
#define buzzer1 18

int PB_ID[10];
int Borrow_mai[10];
int Yu_mai[10];

const String baseUrl = "http://group10.exceed19.online/";

void setup()
{
}

void all_powerbank_staus()
{
  DynamicJsonDocument doc(2048);
  const String url = baseUrl + "/all-powerbank";
  HTTPClient http;
  http.begin(url);
  int httpResponseCode = http.GET();
  if (httpResponseCode == 200)
  {
    String payload = http.getString();
    deserializeJson(doc, payload);
    for (int i = 0; i < ((doc["all_powerbank"]).size()); i++)
    {
      PB_ID[i] = doc["all_powerbank"][i]["powerbank_ID"];
      Borrow_mai[i] = doc["all_powerbank"][i]["borrow_mai"];
      Yu_mai[i] = doc["all_powerbank"][i]["yu_mai"];
    }
  }
  else
  {
    Serial.print("Error ");
    Serial.println(httpResponseCode);
  }
}

void return_laew(int pb_id)
{ 
  const String url = baseUrl + "/return-laew";
  String json;
  DynamicJsonDocument doc(2048);
  doc["powerbank_ID"] = pb_id;
  serializeJson(doc, json);
  HTTPClient http;
  http.begin(url);
  http.addHeader("Content-Type", "application/json");
  int httpResponseCode = http.POST(json);
  if (httpResponseCode >= 200 && httpResponseCode < 300)
  {
    Serial.println(httpResponseCode);
    Serial.println(http.getString());
  }
  else
  {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
}

void pai_laew(int pb_id)
{ 
  const String url = baseUrl + "/pai-laew";
  String json;
  DynamicJsonDocument doc(2048);
  doc["powerbank_ID"] = pb_id;
  serializeJson(doc, json);
  HTTPClient http;
  http.begin(url);
  http.addHeader("Content-Type", "application/json");
  int httpResponseCode = http.POST(json);
  if (httpResponseCode >= 200 && httpResponseCode < 300)
  {
    Serial.println(httpResponseCode);
    Serial.println(http.getString());
  }
  else
  {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
}

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


}