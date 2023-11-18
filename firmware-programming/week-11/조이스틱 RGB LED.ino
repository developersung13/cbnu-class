#include <SoftwareSerial.h>

int analog_x = A0;
int analog_y = A1;
int digital_z = 3;

int LED_RED_PIN = 11;
int LED_GREEN_PIN = 9;
int LED_BLUE_PIN = 10;

void setup() {
    Serial.begin(9600);
    pinMode(analog_x, INPUT_PULLUP);
    pinMode(analog_y, INPUT_PULLUP);
    pinMode(digital_z, INPUT);
    pinMode(LED_RED_PIN, OUTPUT);
    pinMode(LED_GREEN_PIN, OUTPUT);
    pinMode(LED_BLUE_PIN, OUTPUT);
}

void loop() {
    int val_x_a0;
    int val_y_a1;
    int val_z_13;

    val_x_a0 = analogRead(analog_x);
    val_y_a1 = analogRead(analog_y);
    val_z_13 = digitalRead(digital_z);

    Serial.print("X: ");
    Serial.print(val_x_a0);
    Serial.print(", Y: ");
    Serial.print(val_y_a1);
    Serial.print(", Z: ");
    Serial.println(val_z_13);
    delay(200);

    if (val_x_a0 >= 824) {
      RGB_Color(0, 255, 255);
    } else if (val_x_a0 <= 200) {
      RGB_Color(0, 255, 0);
    } else if (val_y_a1 >= 600) {
        RGB_Color(255, 0, 0);
    } else if (val_y_a1 <= 500) {
        RGB_Color(0, 0, 255);
    } else if (val_z_13 == 0) {
        RGB_Color(255, 255, 255);
    } else {
        RGB_Color(0, 0, 0);
    }
}


void RGB_Color(int led_red_val, int led_green_val, int led_blue_val) {
  analogWrite(LED_RED_PIN, led_red_val);
  analogWrite(LED_GREEN_PIN, led_green_val);
  analogWrite(LED_BLUE_PIN, led_blue_val);
}