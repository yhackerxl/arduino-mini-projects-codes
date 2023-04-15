//Arduino solar tracker code

#include <Servo.h> 
 
Servo tracker; 
int eastLDRPin = A5; 
int westLDRPin = A3;
int eastLDR = 0;   
int westLDR = 0;
int difference = 0;
int difference2 = 0;

int trackerPos = 100;    
 
void setup() 
{ 
  tracker.attach(2); 
  pinMode(eastLDRPin, INPUT);
  pinMode(westLDRPin, INPUT);
  Serial.begin(9600);
  tracker.write(trackerPos);
  
  
} 
 
 
void loop() 
{ 
  eastLDR = analogRead(eastLDRPin); 
  westLDR = analogRead(westLDRPin);
  Serial.println(eastLDR);
  Serial.println(westLDR);
  Serial.println("**************");
  difference = eastLDR - westLDR;
  difference2 = westLDR - eastLDR;

  if (difference >= 20 and trackerPos <180){
    trackerPos = trackerPos +2;
    tracker.write(trackerPos);
  }

  if (difference2 >= 20 and trackerPos >0){
    trackerPos = trackerPos -2;
    tracker.write(trackerPos);
  }

  delay(10);

  
}
