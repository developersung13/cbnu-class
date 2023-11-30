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

int fnd_pins[] = { 2, 3, 4, 5, 6, 7, 8, 9 };
int push_btn_pins[] = { 10, 11, 12 };

void setup() {
    Serial.begin(9600);
    for (int k=0; k < 3; k++)
        pinMode(push_btn_pins[k], INPUT_PULLUP);
    for (int k=0; k < 8; k++)
        pinMode(fnd_pins[k], OUTPUT);
}

void loop() {
    int btn_1_ReadValue = digitalRead(push_btn_pins[0]);
    int btn_2_ReadValue = digitalRead(push_btn_pins[1]);
    int btn_3_ReadValue = digitalRead(push_btn_pins[2]);
    Serial.println(btn_1_ReadValue);
    Serial.println(btn_2_ReadValue);
    Serial.println(btn_3_ReadValue);

    if (btn_1_ReadValue == LOW)
        for (int k=0; k < 8; k++)
            digitalWrite(fnd_pins[k], digits[3][k]);

    if (btn_2_ReadValue == LOW)
        for (int k=0; k < 8; k++)
            digitalWrite(fnd_pins[k], digits[6][k]);
    
    if (btn_3_ReadValue == LOW)
        for (int k=0; k < 8; k++)
            digitalWrite(fnd_pins[k], digits[9][k]);
          
    for (int k=0; k < 8; k++)
            digitalWrite(fnd_pins[k], OFF);
}