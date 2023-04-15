int trigPin = 9;    // TRIG pin
int echoPin = 10;    // ECHO pin
const int BUZZER_PIN = 3;
const int DISTANCE_THRESHOLD = 20; // centimeters
float duration_us, distance_cm , distance_m,percentage;

void setup() {
  // begin serial port
  Serial.begin (9600);

  // configure the trigger pin to output mode
  pinMode(trigPin, OUTPUT);
  // configure the echo pin to input mode
  pinMode(echoPin, INPUT);

  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  // generate 10-microsecond pulse to TRIG pin
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(echoPin, HIGH);

  // calculate the distance
 distance_cm = 0.018 * duration_us;
 Serial.println(distance_cm);
// // distance_m = distance_cm * 0.01;
// percentage = (distance_cm * 100)/54;
//
//if(distance_cm < DISTANCE_THRESHOLD)
//    tone(BUZZER_PIN, 1000); // turn on Piezo Buzzer at 1000Hz frequency
//  else
//    noTone(BUZZER_PIN); // turn off Piezo Buzzer
//
//  // print the value to Serial Monitor
//// print the value to Serial Monitor
//Serial.print("distance: ");
////Serial.print(distance_cm);
//Serial.print(100 - percentage);
////Serial.println("cm");
//Serial.println("%");
//
//  delay(3000);
}
