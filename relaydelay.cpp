#include <Arduino.h>
#include <WiFi.h>
#include <MillisTimer.h>

int switchStateLeft=0;
int switchStateRight=0;
const int greenLed=3;
const int redLed=2;
const int switchLeft=5;
const int relay=1;
const int switchRight=4;
unsigned long DELAY_TIME = 60000; // 1.5 sec
unsigned long delayStart = 0; // the time the delay started
bool delayRunning = false; // true if still waiting for delay to finish

bool relayOn = false; // keep track of the led state

void setup() {
  // put your setup code here, to run once:
pinMode(switchLeft,INPUT);
pinMode(switchRight,INPUT);
pinMode(greenLed,OUTPUT);
pinMode(redLed,OUTPUT);
pinMode(relay,OUTPUT);
relayOn = false;
}

void loop() {

  // put your main code here, to run repeatedly:
  switchStateLeft=digitalRead(switchLeft);
  switchStateRight=digitalRead(switchRight);
if (switchStateLeft==HIGH){
    delayStart = millis();
  delayRunning = true;
  if (relayOn==false){
  digitalWrite(greenLed,HIGH);
  digitalWrite(relay,HIGH);
  }
}
  if (delayRunning==true && ((millis() - delayStart) >= DELAY_TIME)) {
    relayOn = false;
  digitalWrite(greenLed,LOW);
  digitalWrite(relay,LOW);
  delayRunning=false;
}
if (delayRunning==true && (switchStateRight==HIGH))
 {relayOn = false;
 digitalWrite(redLed,HIGH);
  digitalWrite(greenLed,LOW);
  digitalWrite(relay,LOW);
  delayRunning=false;
  delay(1000);
  digitalWrite(redLed,LOW);
}
}
