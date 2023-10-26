#include <SoftwareSerial.h>
#define BTtx 2
#define BTrx 3
#define LED_RED 13

SoftwareSerial BT(BTtx, BTrx);

char data = 'F';

void setup() {
  BT.begin(9600);
  Serial.begin(9600);
  pinMode(LED_RED, OUTPUT);
}

void loop() {
  if (BT.available() > 0)
    data = BT.read();

  if (data == 'F') {
    digitalWrite(LED_RED, LOW);
    Serial.println("LED OFF");
  } else if (data == 'T') {
    digitalWrite(LED_RED, HIGH);
    Serial.println("LED ON");
  }
}