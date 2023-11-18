#include <SoftwareSerial.h>

int analog_x = A0;
int analog_y = A1;
int digital_z = 3;

void setup() {
    Serial.begin(9600);
    pinMode(analog_x, INPUT_PULLUP);
    pinMode(analog_y, INPUT_PULLUP);
    pinMode(digital_z, INPUT);
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
}