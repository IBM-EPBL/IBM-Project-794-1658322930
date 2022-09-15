// C++ code
//
#include <Servo.h>

int BRIGHTNESS = 0;

int DISTANCE = 0;

int MOTION = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

Servo servo_7;

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
  pinMode(4, INPUT);
  pinMode(13, OUTPUT);
  pinMode(7, OUTPUT);
  servo_7.attach(7, 500, 2500);
  pinMode(2, OUTPUT);
}

void loop()
{
  BRIGHTNESS = analogRead(A0);
  Serial.print("BRIGHTNESS = ");
  Serial.println(BRIGHTNESS);
  DISTANCE = 0.01723 * readUltrasonicDistance(9, 10);
  Serial.print("DISTANCE = ");
  Serial.println(DISTANCE);
  MOTION = digitalRead(4);
  Serial.print("MOTION = ");
  Serial.println(MOTION);
  if (BRIGHTNESS < 900) {
    Serial.println("LIGHT ON -:)");
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }
  if (DISTANCE < 150) {
    Serial.println("DOOR OPEN >>>");
    digitalWrite(7, HIGH);
    servo_7.write(90);
  } else {
    digitalWrite(7, LOW);
    servo_7.write(0);
  }
  if (MOTION == 1) {
    Serial.println("THIEF###");
    digitalWrite(2, HIGH);
  } else {
    digitalWrite(2, LOW);
  }
  Serial.println("---------------------------------------");
  delay(10); // Delay a little bit to improve simulation performance
}