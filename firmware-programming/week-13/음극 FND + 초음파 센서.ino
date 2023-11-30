#define PIN_TRIG 12
#define PIN_ECHO 11

int ON = HIGH;
int OFF = LOW;

long duration;
int distance;

int digits[10][8] = {
    {ON, ON, ON, ON, ON, ON, OFF, OFF},
    {OFF, ON, ON, OFF, OFF, OFF, OFF, OFF},
    {ON, ON, OFF, ON, ON, OFF, ON, OFF},
    {ON, ON, ON, ON, OFF, OFF, ON, OFF},
    {OFF, ON, ON, OFF, OFF, ON, ON, OFF},
    {ON, OFF, ON, ON, OFF, ON, ON, OFF},
    {ON, OFF, ON, ON, ON, ON, ON, OFF},
    {ON, ON, ON, OFF, OFF, OFF, OFF, OFF},
    {ON, ON, ON, ON, ON, ON, ON, OFF},
    {ON, ON, ON, ON, OFF, ON, ON, OFF}
};

int fnd_pins[] = { 2, 3, 4, 5, 6, 7, 8, 9 };

void setup() {
    Serial.begin(9600);
    pinMode(PIN_TRIG, OUTPUT);
    pinMode(PIN_ECHO, INPUT);
    for (int k=0; k < 8; k++)
        pinMode(fnd_pins[k], OUTPUT);
}

void loop() {
    digitalWrite(PIN_TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(PIN_TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(PIN_TRIG, LOW);
  
    duration = pulseIn(PIN_ECHO, HIGH);
    distance = duration * 340 * 100 / 1000000 / 2;

    Serial.print("Distance : ");
    Serial.print(distance);
    Serial.println("cm");

    if (distance < 20) {
        for (int k=0; k < 8; k++)
            digitalWrite(fnd_pins[k], digits[0][k]);
        Serial.println("0~20cm");
    } else if (distance < 40) {
        for (int k=0; k < 8; k++)
            digitalWrite(fnd_pins[k], digits[1][k]);
        Serial.println("21~40cm");
    } else {
        for (int k=0; k < 8; k++)
            digitalWrite(fnd_pins[k], digits[2][k]);
        Serial.println("41cm~");
    }
}