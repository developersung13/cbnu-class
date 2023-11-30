int pin_Laser = 13;

void setup() {
    Serial.begin(9600);
    pinMode(pin_Laser, OUTPUT);
}

void loop() {
    digitalWrite(pin_Laser, HIGH);
    delay(500);
    digitalWrite(pin_Laser, LOW);
    delay(500);
}