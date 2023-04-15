#include <SoftwareSerial.h>
SoftwareSerial BTserial(10, 11); // RX | TX

const int laserPin = 3; // digital output pin for laser diode
const int ldrPin = A0; // analog input pin for LDR

void setup() {
  Serial.begin(9600); // initialize serial communication
  pinMode(laserPin, OUTPUT); // set laser pin as output
  pinMode(ldrPin, INPUT); // set LDR pin as input
  digitalWrite(laserPin, HIGH); // turn off laser
  BTserial.begin(9600); }

void loop() {
int ldrValue = analogRead(ldrPin);
    BTserial.println(ldrValue);
    Serial.println(ldrValue);
if (ldrValue < 20) {
    Serial.println("FULL"); 
    BTserial.println("FULL");// print "FULL" if laser light is blocked
    delay(3000);
  } else {
    BTserial.println("EMPTY");
    Serial.println("EMPTY");// print "EMPTY" if laser light is not blocked
    delay(3000);
  }
  digitalWrite(laserPin, HIGH); // turn off laser
  delay(1000);

}
