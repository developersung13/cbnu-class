int pin_passive = 13;
int button_push = 8;

void setup() {
  Serial.begin(9600);
  pinMode(pin_passive, OUTPUT);
  pinMode(button_push, INPUT_PULLUP);
}

void loop() {
  int readValue = digitalRead(button_push);
  Serial.println(readValue);
  
  if (readValue == LOW)
	tone(pin_passive, 330);
  else
    noTone(pin_passive);
}