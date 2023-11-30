int ON = HIGH;
int OFF = LOW;

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

int pins[] = { 2, 3, 4, 5, 6, 7, 8, 9 };

void setup() {
    Serial.begin(9600);
    for (int k=0; k < 8; k++)
        pinMode(pins[k], OUTPUT);
}

void loop() {
    for (int k=0; k <= 9; k++) {
        for (int z=0; z < 8; z++) {
                digitalWrite(pins[z], digits[k][z]);
        }
        delay(1000);
    }
}