#include <SoftwareSerial.h>
#define BTtx 2
#define BTrx 3
#define LED_RED 13
#define LED_YELLOW 12

SoftwareSerial BT(BTtx, BTrx);

char data = 0;

void setup() {
  BT.begin(9600);
  Serial.begin(9600);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
}

void loop() {
  if (BT.available() > 0)
    data = BT.read() - '0';

  Serial.println(data);

  switch (data) {
    case 0:
      digitalWrite(LED_RED, LOW);
      digitalWrite(LED_YELLOW, LOW);
      Serial.println(data);
      break;
    case 1:
      digitalWrite(LED_RED, HIGH);
      digitalWrite(LED_YELLOW, LOW);
      break;
    case 2:
      digitalWrite(LED_RED, LOW);
      digitalWrite(LED_YELLOW, HIGH);
      break;
    case 3:
      digitalWrite(LED_RED, HIGH);
      digitalWrite(LED_YELLOW, HIGH);
  }
}