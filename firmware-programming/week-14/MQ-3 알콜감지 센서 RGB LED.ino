int pin_mq3 = A5;
int pin_red = 11;
int pin_green = 9;
int pin_blue = 10;

void setup() {
    Serial.begin(9600);
    pinMode(pin_red, OUTPUT);
    pinMode(pin_green, OUTPUT);
    pinMode(pin_blue, OUTPUT);
}

void loop() {
    int val = analogRead(pin_mq3);
    Serial.println(analogRead(val));

    if (val >= 400) {
        RGB_Color(255, 0, 0);
    } else if (val >= 200 && val < 400) {
        RGB_Color(0, 255, 0);
    } else {
        RGB_Color(0, 0, 255);
    }
}

void RGB_Color(int led_red_val, int led_green_val, int led_blue_val) {
  analogWrite(LED_RED_PIN, led_red_val);
  analogWrite(LED_GREEN_PIN, led_green_val);
  analogWrite(LED_BLUE_PIN, led_blue_val);
}