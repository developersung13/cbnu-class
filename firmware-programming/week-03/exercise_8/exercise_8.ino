int LED_RED_PIN = 11;
int LED_GREEN_PIN = 10;
int LED_BLUE_PIN = 9;
int POT_LED = A1;
int val_sensor_led = 0;
int val_output_led = 0;

void setup() {
  pinMode(LED_RED_PIN, OUTPUT);
  pinMode(LED_GREEN_PIN, OUTPUT);
  pinMode(LED_BLUE_PIN, OUTPUT);
}

void loop() {
  val_sensor_led = analogRead(POT_LED);
  val_output_led = map(val_sensor_led, 0, 1023, 0 , 255);
  RGB_Color(255, 255, val_output_led);
}

void RGB_Color(int led_red_val, int led_green_val, int led_blue_val) {
  analogWrite(LED_RED_PIN, led_red_val);
  analogWrite(LED_GREEN_PIN, led_green_val);
  analogWrite(LED_BLUE_PIN, led_blue_val);
}