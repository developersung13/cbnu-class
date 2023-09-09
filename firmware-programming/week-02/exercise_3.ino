// Serial Monitor, LED
int LED = 13;
void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

int serialData;
void loop() {
  if (Serial.available() > 0) {
    serialData = Serial.read();
    Serial.println(serialData);
    if (serialData == '1')
      digitalWrite(LED, HIGH);
    else if (serialData == '0')
      digitalWrite(LED, LOW);
    else if (serialData == 'a' || serialData == 'A') {
      for (int k=0; k < 2; k++) {
        digitalWrite(LED, HIGH);
        delay(200);
        digitalWrite(LED, LOW);
        delay(200);
      }
    }
  }
}