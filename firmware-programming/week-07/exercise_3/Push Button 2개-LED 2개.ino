int led_red = 13;
int led_blue = 12;
int button1_push = 9;
int button2_push = 8;

void setup() {
  Serial.begin(9600);
  pinMode(led_red, OUTPUT);
  pinMode(led_blue, OUTPUT);

}

void loop() {
  int readValue1 = digitalRead(button1_push);
  int readValue2 = digitalRead(button2_push);
  Serial.println(readValue1);
  Serial.println(readValue2);
  
  if (readValue1 == LOW)
    digitalWrite(led_red, LOW);
  else
    digitalWrite(led_red, HIGH);
  
  if (readValue2 == LOW)
    digitalWrite(led_blue, LOW);
  else
    digitalWrite(led_blue, HIGH);
}