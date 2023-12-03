int pin_cds = A0;
int val = 0;

void setup() {
    Serial.begin(9600);
    pinMode(pin_cds, INPUT);
}

void loop() {
    val = analogRead(pin_cds);
    Serial.println(val);
}