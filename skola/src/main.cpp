#include <Arduino.h>
int cerPin = 2;
int zluPin = 3;
int zelPin = 4;
int tlaPin = 5;
int stat = 0;

void setup(){
pinMode(cerPin, OUTPUT);  
pinMode(zluPin, OUTPUT);
pinMode(zelPin, OUTPUT);
pinMode(tlaPin, INPUT);
}

void loop(){
if (digitalRead(tlaPin)){
if (stat == 0){
digitalWrite(cerPin,HIGH);
digitalWrite(zluPin,LOW);
digitalWrite(zelPin,LOW);
stat = 1;
}
else if (stat == 1){
digitalWrite(cerPin,HIGH);
digitalWrite(zluPin,HIGH);
digitalWrite(zelPin,LOW);
stat = 2;
}
else if (stat == 2){
digitalWrite(cerPin,LOW);
digitalWrite(zluPin,LOW);
digitalWrite(zelPin,HIGH);
stat = 3;
}
else if (stat == 3){
digitalWrite(cerPin,LOW);
digitalWrite(zluPin,HIGH);
digitalWrite(zelPin,LOW);
stat = 0;
}
delay(1000); 
}
}
void setLights(int cer, int zlu, int zel){
digitalWrite(cerPin, cer);
digitalWrite(zluPin, zlu);
digitalWrite(zelPin, zel );
}

