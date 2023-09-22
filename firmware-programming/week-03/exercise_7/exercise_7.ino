int LED_RED_PIN = 11;
int LED_GREEN_PIN = 10;
int LED_BLUE_PIN = 9;

void setup() {
  Serial.begin(9600);
  pinMode(LED_RED_PIN, OUTPUT);
  pinMode(LED_GREEN_PIN, OUTPUT);
  pinMode(LED_BLUE_PIN, OUTPUT);
}

int serialData;

void loop() {
  if (Serial.available() > 0) {
    serialData = Serial.read();
    Serial.println(serialData);

    switch (serialData) {
      case 'r':
      case 'R':
        RGB_Color(255, 0, 0);
        break;
      case 'g':
      case 'G':
        RGB_Color(0, 255, 0);
        break;
      case 'b':
      case 'B':
        RGB_Color(0, 0, 255);
        break;
    }
  }
}

void RGB_Color(int led_red_val, int led_green_val, int led_blue_val) {
  analogWrite(LED_RED_PIN, led_red_val);
  analogWrite(LED_GREEN_PIN, led_green_val);
  analogWrite(LED_BLUE_PIN, led_blue_val);
}