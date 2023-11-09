#include <SoftwareSerial.h>
#include <Servo.h>

Servo myServo;

int BT_TX = 2;
int BT_RX = 3;

SoftwareSerial BT(BT_TX, BT_RX);

void setup() {
    myServo.attach(9);
    Serial.begin(9600);
    BT.begin(9600);
}

void loop() {
    if (BT.available() > 0) {
        int servoPos = BT.read();
        Serial.println(servoPos);
        myServo.write(servoPos);
    }
}