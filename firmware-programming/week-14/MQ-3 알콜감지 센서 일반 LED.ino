int pin_mq3 = A5;
int pin_red = 11;

void setup() {
    Serial.begin(9600);
    pinMode(pin_red, OUTPUT);
}

void loop() {
    int val = analogRead(pin_mq3);
    Serial.println(analogRead(val));

    if (val >= 400) {
        digitalWrite(pin_red, HIGH);
    } else {
        digitalWrite(pin_red, LOW);
    }
}