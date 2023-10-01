int pin_active = 10;

void setup() {
  pinMode(pin_active, OUTPUT);
}

void loop() {
  tone(pin_active, HIGH);
  delay(1000);
  noTone(pin_active);
  delay(1000);
}