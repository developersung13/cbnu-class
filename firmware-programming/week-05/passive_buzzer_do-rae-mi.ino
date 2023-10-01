int pin_passive = 10;

void setup() {
  pinMode(pin_passive, OUTPUT);
}

void loop() {
  tone(pin_passive, 262);
  delay(500);
  noTone(pin_passive);
  delay(500);
    tone(pin_passive, 294);
  delay(500);
  noTone(pin_passive);
  delay(500);
    tone(pin_passive, 330);
  delay(500);
  noTone(pin_passive);
  delay(500);
}