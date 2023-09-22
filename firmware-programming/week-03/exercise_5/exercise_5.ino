// 가변저항 값과 LED 밝기 : 시리얼 모니터에 출력
int LED_GREEN = 9;
int POT_GREEN = A1;
int val_sensor_green = 0;
int val_output_green = 0;

void setup() {
  pinMode(LED_GREEN, OUTPUT);
  pinMode(POT_GREEN, INPUT);
  Serial.begin(9600);
}

void loop() {
  val_sensor_green = analogRead(POT_GREEN);
  val_output_green = map(val_sensor_green, 0, 1023, 0, 255);
  Serial.print("Potentionmeter Value = ");
  Serial.print(val_sensor_green);
  Serial.print(", LED's Bright = ");
  Serial.println(val_output_green);
  analogWrite(LED_GREEN, val_output_green);
  delay(10);
}