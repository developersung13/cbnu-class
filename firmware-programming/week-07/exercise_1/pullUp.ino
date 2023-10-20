int led_red = 13;
int button_push = 8;

void setup() {
  Serial.begin(9600);
  pinMode(led_red, OUTPUT);
  pinMode(button_push, INPUT_PULLUP);
}

void loop() {
  int readValue = digitalRead(button_push);
  Serial.println(readValue);
  
  if (readValue == HIGH)
    digitalWrite(led_red, HIGH);
  else
    digitalWrite(led_red, LOW);
}