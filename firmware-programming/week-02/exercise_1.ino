//int pin_LED = 13;
#define pin_LED 13

void setup() {
  pinMode(pin_LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(pin_LED, HIGH); // 출력
  delay(1000); // 위 코드라인 한 줄 1초 유지
  digitalWrite(pin_LED, LOW);
  delay(1000);
  digitalWrite(pin_LED, HIGH);
  delay(500);
  digitalWrite(pin_LED, LOW);
  delay(500);
}