int pin_cds = A0;
int pin_led = 13;
int val = 0;

void setup() {
    Serial.begin(9600);
    pinMode(pin_led, OUTPUT);
    pinMode(pin_cds, INPUT);
}

void loop() {
    val = analogRead(pin_cds);
    Serial.println(val);

    if (val >= 200) {
        digitalWrite(pin_led, HIGH);
    } else {
        digitalWrite(pin_led, LOW);
    }
}