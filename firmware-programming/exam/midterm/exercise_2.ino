int pin_trig = 12;
int pin_echo = 11;
int pin_passive = 6;

int led_red_pin = 10;
int led_green_pin = 9;
int led_blue_pin = 8;

long duration;
int distance;

int melody_1[] = { 262 };
int duration_s_1[] = { 8 };

int melody_2[] = { 262, 262, 0 };
int duration_s_2[] = { 8, 8, 8 };

int melody_3[] = { 262, 262, 262, 0 };
int duration_s_3[] = { 8, 8, 8, 8 };

int melody_4[] = { 262 };
int duration_s_4[] = { 16 };

 void setup() {
  Serial.begin(9600);
  pinMode(pin_passive, OUTPUT);
  pinMode(pin_trig, OUTPUT);
  pinMode(pin_echo, INPUT);
  pinMode(led_red_pin, OUTPUT);
  pinMode(led_green_pin, OUTPUT);
  pinMode(led_blue_pin, OUTPUT);
  // Serial.println("test");
 }

void loop() {
  digitalWrite(pin_trig, LOW);
  delayMicroseconds(2);
  digitalWrite(pin_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pin_trig, LOW);
  
  duration = pulseIn(pin_echo, HIGH);
  distance = duration * 340 * 100 / 1000000 / 2;
  
  Serial.print("Distance : ");
  Serial.print(distance);
  Serial.println("cm");

  if (distance >= 41 || distance < 0) {
    RGB_Color(0, 0, 0);
    for(int sounds = 0; sounds < 1; sounds++) {
      int Duration = 1000 / duration_s_1[sounds];
      tone(pin_passive, melody_1[sounds]);
      delay(Duration);
   
      float pauseSound = Duration * 1.3;
      noTone(pin_passive);
      delay(pauseSound);
    }
  } else if (distance >= 31) {
    RGB_Color(0, 0, 255);
    for(int sounds = 0; sounds < 3; sounds++) {
      int Duration = 1000 / duration_s_2[sounds];
      tone(pin_passive, melody_2[sounds]);
      delay(Duration);
   
      float pauseSound = Duration * 1.3;
      noTone(pin_passive);
      delay(pauseSound);
    }
  } else if (distance >= 21) {
    RGB_Color(0, 255, 0);
    for(int sounds = 0; sounds < 4; sounds++) {
      int Duration = 1000 / duration_s_3[sounds];
      tone(pin_passive, melody_3[sounds]);
      delay(Duration);
   
      float pauseSound = Duration * 1.3;
      noTone(pin_passive);
      delay(pauseSound);
    }
  } else {
    RGB_Color(255, 0, 0);
    for(int sounds = 0; sounds < 1; sounds++) {
      int Duration = 1000 / duration_s_4[sounds];
      tone(pin_passive, melody_4[sounds]);
      delay(Duration);
   
      float pauseSound = Duration * 1.3;
      noTone(pin_passive);
      delay(pauseSound);
    }
  }

  Serial.print("Distance: ");
  Serial.println(distance);
}

void RGB_Color(int led_red_val, int led_green_val, int led_blue_val) {
  analogWrite(led_red_pin, led_red_val);
  analogWrite(led_green_pin, led_green_val);
  analogWrite(led_blue_pin, led_blue_val);
}