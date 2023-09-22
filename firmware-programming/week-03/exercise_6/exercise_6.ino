int LED_RED_PIN = 11;
int LED_GREEN_PIN = 10;
int LED_BLUE_PIN = 9;

void setup() {
  pinMode(LED_RED_PIN, OUTPUT);
  pinMode(LED_GREEN_PIN, OUTPUT);
  pinMode(LED_BLUE_PIN, OUTPUT);
}

void loop() {
  RGB_Color(255, 0, 0);
  delay(1000);
  RGB_Color(0, 0, 0);
  delay(1000);
  RGB_Color(0, 255, 0);
  delay(1000);
  RGB_Color(0, 0, 0);
  delay(1000);
  RGB_Color(255, 255, 0);
  delay(1000);
}

void RGB_Color(int led_red_val, int led_green_val, int led_blue_val) {
  analogWrite(LED_RED_PIN, led_red_val);
  analogWrite(LED_GREEN_PIN, led_green_val);
  analogWrite(LED_BLUE_PIN, led_blue_val);
}