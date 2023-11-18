#include <SoftwareSerial.h>

int analog_x = A0;
int analog_y = A1;
int digital_z = 3;

int pinHorizon = A0;
int pinVertical = A1;
int stateButton1 = 0;
int stateButton2 = 0;
int pin_led_left = 8;
int pin_led_right = 9;
int pin_led_up = 10;
int pin_led_down = 11;
int pin_led_button = 12;

void setup() {
    Serial.begin(9600);
    pinMode(analog_x, INPUT_PULLUP);
    pinMode(analog_y, INPUT_PULLUP);
    pinMode(digital_z, INPUT);
    pinMode(pin_led_up, OUTPUT);
    pinMode(pin_led_down, OUTPUT);
    pinMode(pin_led_left, OUTPUT);
    pinMode(pin_led_right, OUTPUT);
    pinMode(pin_led_button, OUTPUT);
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
        digitalWrite(pin_led_right, HIGH);
    } else if (val_x_a0 <= 200) {
        digitalWrite(pin_led_left, HIGH);
    } else if (val_y_a1 >= 600) {
        digitalWrite(pin_led_up, HIGH);
    } else if (val_y_a1 <= 500) {
        digitalWrite(pin_led_down, HIGH);
    } else if (val_z_13 == 0) {
        digitalWrite(pin_led_button, HIGH);
    } else {
        digitalWrite(pin_led_left, LOW);
        digitalWrite(pin_led_right, LOW);
        digitalWrite(pin_led_up, LOW);
        digitalWrite(pin_led_down, LOW);
        digitalWrite(pin_led_button, LOW);
    }
}