#define C4 262
#define C4s 277
#define D4 294
#define D4s 311
#define E4 330
#define F4 349
#define F4s 370
#define G4 392
#define G4s 415
#define A4 440
#define A4s 466
#define B4 494
#define C5 523

int pin_passive = 9;
int led_c4 = 10;
int led_d4 = 11;
int led_e4 = 12;
int led_f4 = 13;

int melody[] = { C4, D4, E4, C4, E4, C4, E4, D4, E4, F4, F4, E4, D4, F4 };
int duration_s[] = { 4, 6, 4, 6, 4, 4, 2, 2, 4, 6, 6, 6, 6, 1 };
int led_s[] = {led_c4, led_d4, led_e4, led_c4, led_e4, led_c4, led_e4, led_d4, led_e4, led_f4, led_f4, led_e4, led_d4, led_f4 };

void setup() {
  pinMode(pin_passive, OUTPUT);
  pinMode(led_c4, OUTPUT);
  pinMode(led_d4, OUTPUT);
  pinMode(led_e4, OUTPUT);
}

void loop() {
  for(int sounds = 0; sounds < 14; sounds++){
    int Duration = 1000 / duration_s[sounds];
   tone(pin_passive, melody[sounds]);
    digitalWrite(led_s[sounds], HIGH);
    delay(Duration);
    digitalWrite(led_s[sounds], LOW);
   
    float pauseSound = Duration * 1.3;
    noTone(pin_passive);
    delay(pauseSound);
  }

}