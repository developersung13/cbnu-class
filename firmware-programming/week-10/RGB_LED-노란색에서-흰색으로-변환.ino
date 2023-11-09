#include <SoftwareSerial.h>

int BT_TX = 2;
int BT_RX = 3;

int LED_RED_PIN = 11;
int LED_GREEN_PIN = 10;
int LED_BLUE_PIN = 9;

SoftwareSerial BT(BT_TX, BT_RX);

int data = 0;

void setup() {
    Serial.begin(9600);
    BT.begin(9600);
    pinMode(LED_RED_PIN, OUTPUT);
    pinMode(LED_GREEN_PIN, OUTPUT);
    pinMode(LED_BLUE_PIN, OUTPUT);
}

void loop() {
    if (BT.available() > 0) {
        data = BT.read();
        Serial.println(data);

        int mapped_blue_val = map(data, 0, 180, 0, 255);
        RGB_Color(255, 255, mapped_blue_val);
    }
}

void RGB_Color(int led_red_val, int led_green_val, int led_blue_val) {
  analogWrite(LED_RED_PIN, led_red_val);
  analogWrite(LED_GREEN_PIN, led_green_val);
  analogWrite(LED_BLUE_PIN, led_blue_val);
}