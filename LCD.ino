#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int LDR_PIN = A0; // LDR connected to analog pin A0
const int LED_PIN = 10; // LED connected to digital pin 9
int laserPin = 9;

void setup() {
  pinMode(laserPin, OUTPUT); 
  pinMode(LED_PIN, OUTPUT); // set LED pin as output
  Serial.begin(9600); // initialize serial communication
  lcd.init(); // initialize the LCD display
  
  lcd.backlight();
}

void loop() {
  digitalWrite(laserPin, HIGH);
  int sensorValue = analogRead(LDR_PIN); // read LDR value
  lcd.setCursor(0,0); // set cursor to the first column and first row
  lcd.print(" LDR Value: "); // print the label
  lcd.print(sensorValue); // print the LDR value
  if (sensorValue < 400) {
    digitalWrite(LED_PIN, LOW); // turn LED on
  } else {
    digitalWrite(LED_PIN, HIGH); // turn LED off
  }
  
  delay(10); // wait for 100 milliseconds
}
