int ON = HIGH;
int OFF = LOW;

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
int pin_mq3 = A5;

void setup() {
    Serial.begin(9600);
    for (int k=0; k < 8; k++)
        pinMode(fnd_pins[k], OUTPUT);
}

void loop() {
    int val = analogRead(pin_mq3);
    Serial.println(analogRead(val));

    if (val >= 301) {
        for (int k=0; k < 8; k++)
            digitalWrite(fnd_pins[k], digits[3][k]);
    } else if (val >= 201 && val <= 300) {
        for (int k=0; k < 8; k++)
            digitalWrite(fnd_pins[k], digits[2][k]);
    } else if (val >= 101 && val <= 200) {
        for (int k=0; k < 8; k++)
            digitalWrite(fnd_pins[k], digits[1][k]);
    } else {
        for (int k=0; k < 8; k++)
            digitalWrite(fnd_pins[k], digits[0][k]);
    }
}