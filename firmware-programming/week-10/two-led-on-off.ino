#include <SoftwareSerial.h>

#define BTtx 2
#define BTrx 3
#define LED_RED 13
#define LED_YELLOW 12

SoftwareSerial BT(BTtx, BTrx);

char data = 'F';

void setup() {
    BT.begin(9600);
    Serial.begin(9600);
    pinMode(LED_RED, OUTPUT);
    pinMode(LED_YELLOW, OUTPUT);
}

void loop() {
    if (BT.available() > 0)
        data = BT.read();

    if (data == 'A') {
        digitalWrite(LED_RED, HIGH);
        digitalWrite(LED_YELLOW, LOW);
        Serial.println("A");
    } else if (data == 'B') {
        digitalWrite(LED_RED, LOW);
        digitalWrite(LED_YELLOW, HIGH);
        Serial.println("B");
    } else if (data == 'C') {
        digitalWrite(LED_RED, HIGH);
        digitalWrite(LED_YELLOW, HIGH);
        Serial.println("C");
    } else {
        digitalWrite(LED_RED, LOW);
        digitalWrite(LED_YELLOW, LOW);
        Serial.println("D");
    }
}