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
}