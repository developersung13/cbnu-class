int pin_passive = 10;

void setup() {
  pinMode(pin_passive, OUTPUT);
}

void loop() {
  tone(pin_passive, 262);
  delay(1000);
  noTone(pin_passive);
  delay(1000);f 
}