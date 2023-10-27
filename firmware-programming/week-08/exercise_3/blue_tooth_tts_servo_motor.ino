#include <SoftwareSerial.h>
#include <Servo.h>

#define BTtx 2
#define BTrx 3

Servo myservo;

int pin_servo = 10;

SoftwareSerial BT(BTtx, BTrx);

int data = -1;

void setup() {
  BT.begin(9600);
  Serial.begin(9600);
  myservo.attach(pin_servo);
}

void loop() {
  if (BT.available() > 0)
    data = BT.read();
    
  if (data == 1) { 
    myservo.write(0);
    Serial.print("BLUETOOTH Response: ");
    Serial.println(data);
  } else if (data == 90) {
    myservo.write(90);
    Serial.print("BLUETOOTH Response: ");
    Serial.println(data);
  } else if (data == 180) {
    myservo.write(180);
    Serial.print("BLUETOOTH Response: ");
    Serial.println(data);
  }
}