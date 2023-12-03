int pin_cds = A0;
int pin_red = 11;
int pin_green = 10;
int pin_blue = 9;

void setup() {
    Serial.begin(9600);
    pinMode(pin_red, OUTPUT);
    pinMode(pin_green, OUTPUT);
    pinMode(pin_blue, OUTPUT);
    pinMode(pin_cds, INPUT);
}

void loop() {
    int val = analogRead(pin_cds);
    Serial.println(val);

    if (val >= 200) {
        RGB_Color(255, 0, 0);
    } else if (val >= 100 && val < 200) {
        RGB_Color(0, 255, 0);
    } else {
    	RGB_Color(0, 0, 255);
    }
}

void RGB_Color(int led_red_val, int led_green_val, int led_blue_val) {
  analogWrite(pin_red, led_red_val);
  analogWrite(pin_green, led_green_val);
  analogWrite(pin_blue, led_blue_val);
}