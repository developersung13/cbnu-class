#include <SoftwareSerial.h>

int ON = HIGH;
int OFF = LOW;

int analog_x = A0;
int analog_y = A1;
int digital_z = 11;

int digits[10][8] = {
    {ON, ON, ON, ON, ON, ON, OFF, OFF},
    {OFF, ON, ON, OFF, OFF, OFF, OFF, OFF},
    {ON, ON, OFF, ON, ON, OFF, ON, OFF},
    {ON, ON, ON, ON, OFF, OFF, ON, OFF},
    {OFF, ON, ON, OFF, OFF, ON, ON, OFF},
    {ON, OFF, ON, ON, OFF, ON, ON, OFF},
    {ON, OFF, ON, ON, ON, ON, ON, OFF},
    {ON, ON, ON, OFF, OFF, OFF, OFF, OFF},
    {ON, ON, ON, ON, ON, ON, ON, OFF},
    {ON, ON, ON, ON, OFF, ON, ON, OFF}
};

int fnd_pins[] = { 2, 3, 4, 5, 6, 7, 8, 9 };

void setup() {
    Serial.begin(9600);
    pinMode(analog_x, INPUT_PULLUP);
    pinMode(analog_y, INPUT_PULLUP);
    pinMode(digital_z, INPUT);
    for (int k=0; k < 8; k++)
      pinMode(fnd_pins[k], OUTPUT);
}

void loop() {
    int val_x_a0;
    int val_y_a1;
    int val_z_13;

    val_x_a0 = analogRead(analog_x);
    val_y_a1 = analogRead(analog_y);
    val_z_13 = digitalRead(digital_z);

    // Serial.print("X: ");
    // Serial.print(val_x_a0);
    // Serial.print(", Y: ");
    // Serial.print(val_y_a1);
    // Serial.print(", Z: ");
    // Serial.println(val_z_13);

    

    if (val_x_a0 >= 824) {
      for (int k=0; k < 8; k++)
            digitalWrite(fnd_pins[k], digits[3][k]);
      Serial.println("Left(3)");
    } else if (val_x_a0 <= 200) {
      for (int k=0; k < 8; k++)
            digitalWrite(fnd_pins[k], digits[4][k]);
      Serial.println("Right(4)");
    } else if (val_y_a1 >= 600) {
        for (int k=0; k < 8; k++)
            digitalWrite(fnd_pins[k], digits[1][k]);
      Serial.println("Up(1)");
    } else if (val_y_a1 <= 500) {
        for (int k=0; k < 8; k++)
            digitalWrite(fnd_pins[k], digits[2][k]);
      Serial.println("Down(2)");
    } else {
        for (int k=0; k < 8; k++)
            digitalWrite(fnd_pins[k], digits[0][k]);
        Serial.println("Center(0)");
    }

    delay(200);
}