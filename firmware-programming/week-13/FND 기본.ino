#define pin_A 2
#define pin_B 3
#define pin_C 4
#define pin_D 5
#define pin_E 6
#define pin_F 7
#define pin_G 8
#define pin_DP 9

void setup() {
    Serial.begin(9600);
    pinMode(pin_A, OUTPUT);
    pinMode(pin_B, OUTPUT);
    pinMode(pin_C, OUTPUT);
    pinMode(pin_D, OUTPUT);
    pinMode(pin_E, OUTPUT);
    pinMode(pin_F, OUTPUT);
    pinMode(pin_G, OUTPUT);
    pinMode(pin_DP, OUTPUT);
}

void loop() {
    digitalWrite(pin_A, HIGH);
    digitalWrite(pin_B, HIGH);
    digitalWrite(pin_C, HIGH);
    digitalWrite(pin_D, HIGH);
    digitalWrite(pin_E, HIGH);
    digitalWrite(pin_F, HIGH);
    digitalWrite(pin_G, HIGH);
    digitalWrite(pin_DP, HIGH);
}