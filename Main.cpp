#include <Arduino.h>
#include <hcsr04.h>
#include <Servo.h>

int tpin=8;
int epin=9; 
float pingtime;
float distance;
float spd=776.5;
float servoAngle;
Servo mServ;
int pos =0;


void setup() {
  Serial.begin(9600);
  mServ.attach(7);
  pinMode(tpin, OUTPUT);
  pinMode(epin, INPUT);
  } 

void loop() {
  digitalWrite(tpin, LOW);
  delayMicroseconds(2000);
  digitalWrite(tpin, HIGH);
  delayMicroseconds(15);
  digitalWrite(tpin, LOW);
  delayMicroseconds(10);
  pingtime =pulseIn(epin, HIGH);
  pingtime=pingtime/1000000;
  pingtime=pingtime/3600;
  distance=spd*pingtime;
  distance=distance/2;
  distance=distance*63360;
  Serial.println(distance);
if (distance <= 3.00)
  {
   mServ.write(pos = 30);
   delay(20);
  }
else
  {
   mServ.write(pos = 0);
   delay(20);
  }
  
}
