int pin_poten = A0;

void setup() {
 Serial.begin(9600);
  pinMode(pin_poten, INPUT);
}

void loop() {
  int readValue = analogRead(pin_poten);
  Serial.println(readValue);
}