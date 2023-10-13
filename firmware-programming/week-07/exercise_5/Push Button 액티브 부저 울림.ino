int pin_active = 10;
int button_push = 8;

void setup() {
  Serial.begin(9600);
  pinMode(pin_active, OUTPUT);
  pinMode(button_push, INPUT_PULLUP);
}

void loop() {
  int readValue = digitalRead(button_push);
  Serial.println(readValue);
  
  if (readValue == LOW)
	  tone(pin_active, HIGH);
  else
    noTone(pin_active);