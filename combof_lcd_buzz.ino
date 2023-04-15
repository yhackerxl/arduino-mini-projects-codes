#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int BUZZER_PIN = 3;
const int trigPin = 7; 
const int echoPin = 8;
const int laserPin = 9;   
const int LED_PIN = 10; 
const int LDR_PIN = A0; 


const int DISTANCE_THRESHOLD = 10; 
//const int empty = 70;
const int lengthofdustbin = 17;
//const int lengthofdustbinn = 40;
int duration_us, distance_cm , distance_m,percentage;

void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(laserPin, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  
  lcd.setCursor(7, 0);
  lcd.print(" STREET-A");
}

void loop() {

  digitalWrite(laserPin, HIGH);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  int sensorValue = analogRead(LDR_PIN);
  //delay(500);
  duration_us = pulseIn(echoPin, HIGH);
  distance_cm = 0.018 * duration_us;
  percentage = (distance_cm*100)/56;
  lcd.setCursor(0, 0);
//  lcd.print(distance_cm);
  lcd.print(percentage);
  lcd.setCursor(2, 0);
  lcd.print("%");
 // delay(2000);

  if(distance_cm < DISTANCE_THRESHOLD /*and sensorValue < 400*/ ) {
    tone(BUZZER_PIN,2000); 
    digitalWrite(LED_PIN, LOW);
    digitalWrite(laserPin, HIGH);
    lcd.setCursor(5, 1);
    lcd.print("FULL");
  }
  //else if(distance_cm <  empty && distance_cm > DISTANCE_THRESHOLD){
   // tone(BUZZER_PIN, 500); 
   // lcd.setCursor(5, 1);
   // lcd.print("Empty");
  //}
   //else if(distance_cm >= lengthofdustbinn and distance_cm <= lengthofdustbin
//   ){
//    tone(BUZZER_PIN, 500); 
//    lcd.setCursor(5, 1);
//    lcd.print("Empty");
//  }
  else {
    noTone(BUZZER_PIN);
    lcd.setCursor(5, 1);
    lcd.print("NOT  ");
    digitalWrite(LED_PIN, HIGH);
    //lcd.setCursor(1, 3);
    //lcd.print(sensorValue);
  }

  delay(1000);
}
