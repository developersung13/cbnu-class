int led_red_pin = 11;
int led_green_pin = 9;
int led_blue_pin = 10;
int button_push1 = 13;
int button_push2 = 4;
int button_push3 = 2;

void setup() {
  Serial.begin(9600);
  pinMode(led_red_pin, OUTPUT);
  pinMode(led_green_pin, OUTPUT);
  pinMode(led_blue_pin, OUTPUT);
  pinMode(button_push1, INPUT_PULLUP);
  pinMode(button_push2, INPUT_PULLUP);
  pinMode(button_push3, INPUT_PULLUP);
}

void loop() {
  int readValue1 = digitalRead(button_push1);
  int readValue2 = digitalRead(button_push2);
  int readValue3 = digitalRead(button_push3);
  Serial.println(readValue1);
  Serial.println(readValue2);
  Serial.println(readValue3);
  
  if (readValue1 == LOW)
    RGB_Color(255, 0, 0);
  else if (readValue2 == LOW)
    RGB_Color(0, 255, 0);
  else if (readValue3 == LOW)
    RGB_Color(0, 0, 255);
}

void RGB_Color(int led_red_val, int led_green_val, int led_blue_val) {
  analogWrite(led_red_pin, led_red_val);
  analogWrite(led_green_pin, led_green_val);
  analogWrite(led_blue_pin, led_blue_val);
}