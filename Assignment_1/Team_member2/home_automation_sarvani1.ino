// C++ code
//
#include <Servo.h>

int dist = 0;

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

Servo servo_8;

void setup()
{
  servo_8.attach(8, 500, 2500);
  pinMode(2, INPUT);
  pinMode(12, OUTPUT);
  pinMode(A1, INPUT);
  pinMode(10, OUTPUT);
}

void loop()
{
  dist = 0.01723 * readUltrasonicDistance(6, 6);
  if (dist < 75) {
    servo_8.write(90);
    delay(3000); // Wait for 3000 millisecond(s)
  } else {
    servo_8.write(0);
  }
  if (digitalRead(2) >= 1) {
    digitalWrite(12, HIGH);
    delay(4000); // Wait for 4000 millisecond(s)
  } else {
    digitalWrite(12, LOW);
  }
  if (analogRead(A1) >= 25) {
    digitalWrite(10, HIGH);
  } else {
    digitalWrite(10, LOW);
  }
}