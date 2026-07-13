#include <Arduino.h>
long incomingText = 0;
unsigned long holdingTime = 0;
const unsigned long holdTimeout = 320;

int red = 11;
int blue = 10;
int green = 12;
int yellow = 13;

void setup() {
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
}

void loop() {
  if(Serial.available() > 0) {
    incomingText = Serial.read();
    if(incomingText == 65) {
      holdingTime = millis();
      digitalWrite(red, HIGH);
      digitalWrite(green, LOW);
    } else if(incomingText == 66){
      holdingTime = millis();
      digitalWrite(red, LOW);
      digitalWrite(green, HIGH);
    } else if(incomingText == 67) {
      holdingTime = millis();
      digitalWrite(blue, HIGH);
      digitalWrite(yellow, LOW);
    } else if(incomingText == 68) {
      holdingTime = millis();
      digitalWrite(blue, LOW);
      digitalWrite(yellow, HIGH);
    }
    else {
      digitalWrite(red, LOW);
      digitalWrite(blue, LOW);
      digitalWrite(green, LOW);
      digitalWrite(yellow, LOW);
      
    }
  }
  if(millis() - holdingTime > holdTimeout) {
    digitalWrite(red, LOW);
    digitalWrite(blue, LOW);
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
    
  }
}
