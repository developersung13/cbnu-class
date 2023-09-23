#include <Servo.h>

int pos = 0;
int pin_servo = 10;

Servo myservo;

void setup() {
  myservo.attach(pin_servo);
}

void loop() {
  myservo.write(0);
  delay(1000);
  myservo.write(90);
  delay(1000);
  myservo.write(180);
  delay(1000);
  myservo.write(90);
  delay(1000);
  myservo.write(0);
  delay(1000);
}