#include <SoftwareSerial.h>
#define BTtx 2
#define BTrx 3

int LED_RED_PIN = 11;
int LED_GREEN_PIN = 9;
int LED_BLUE_PIN = 10;

SoftwareSerial BT(BTtx, BTrx);

char data = 'F';

void setup() {
  BT.begin(9600);
  Serial.begin(9600);
  pinMode(LED_RED_PIN, OUTPUT);
  pinMode(LED_GREEN_PIN, OUTPUT);
  pinMode(LED_BLUE_PIN, OUTPUT);
}

void loop() {
  if (BT.available() > 0)
    data = BT.read();

  if (data == 'R') {
    RGB_Color(255, 0, 0);
  } else if (data == 'G') {
    RGB_Color(0, 0, 255);
  } else if (data == 'B') {
    RGB_Color(0, 255, 0);
  }

  Serial.print("BLUETOOTH Response: ");
  Serial.println(data);
}


void RGB_Color(int led_red_val, int led_green_val, int led_blue_val) {
  analogWrite(LED_RED_PIN, led_red_val);
  analogWrite(LED_GREEN_PIN, led_green_val);
  analogWrite(LED_BLUE_PIN, led_blue_val);
}