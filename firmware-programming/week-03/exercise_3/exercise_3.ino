// LED 아날로그 출력
#define LED_RED 11
#define LED_GREEN 10

void setup() {
  Serial.begin(9600);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
}

void loop() {
  for (int valBright = 0; valBright <= 255; valBright++) {
    analogWrite(LED_RED, valBright);
    analogWrite(LED_GREEN, 255 - valBright);
    Serial.print("Red: ");
    Serial.print(valBright);
    Serial.print(", Green: ");
    Serial.println(255 - valBright);
    delay(10);
  }

  for (int valBright = 255; valBright >= 0; valBright--) {
    analogWrite(LED_RED, valBright);
    analogWrite(LED_GREEN, 255 - valBright);
    Serial.print("Red: ");
    Serial.print(valBright);
    Serial.print(", Green: ");
    Serial.println(255 - valBright);
    delay(10);
  }
}