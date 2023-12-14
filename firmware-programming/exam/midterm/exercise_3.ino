int pin_led1 = 10;
int pin_led2 = 9;
int pin_led3 = 6;

int btn_1 = 4;
int btn_2 = 2;

int pin_poten = A1;

void setup() {
  Serial.begin(9600);
  pinMode(pin_led1, OUTPUT);
  pinMode(pin_led2, OUTPUT);
  pinMode(pin_led3, OUTPUT);

  pinMode(btn_1, INPUT);
  pinMode(btn_2, INPUT);

  pinMode(pin_poten, INPUT);
}

void loop() {
  int readPotenVal = analogRead(pin_poten);
  int led_3_val = map(readPotenVal, 0, 1023, 0, 255);

  Serial.println(led_3_val);
  analogWrite(pin_led3, led_3_val);
  delay(30);

  int btn_val_1 = digitalRead(btn_1);
  int btn_val_2 = digitalRead(btn_2);

  if (btn_val_1 == HIGH) {
    digitalWrite(pin_led1, HIGH);
  } else {
    digitalWrite(pin_led1, LOW);
  }
  

  if (btn_val_2 == HIGH) {
    digitalWrite(pin_led2, HIGH);
  } else {
    digitalWrite(pin_led2, LOW);
  }
}