#include <Servo.h>

Servo myservo;

int pinPoten = A0;
int val;

void setup() {
  myservo.attach(9);
}

void loop() {
  val = analogRead(pinPoten);
  val = map(val, 0, 1023, 0, 180);
  myservo.write(val);
  delay(20);
}