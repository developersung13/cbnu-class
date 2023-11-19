#include <IRremote.h>

#define IR_RECEIVE_PIN 8
#define IR_BUTTON_1 69
#define IR_BUTTON_2 70
#define LED_RED 12
#define LED_GREEN 11

byte state_led_red = LOW;
byte state_led_green = LOW;

void setup() {
    Serial.begin(9600);
    IrReceiver.begin(IR_RECEIVE_PIN);
    pinMode(LED_RED, OUTPUT);
    pinMode(LED_GREEN, OUTPUT);
}

void loop() {
    if (IrReceiver.decode()) {
        IrReceiver.resume();
        int command = IrReceiver.decodedIRData.command;
        switch (command) {
            case IR_BUTTON_1: {
                state_led_red = (state_led_red == LOW) ? HIGH : LOW;
                digitalWrite(LED_RED, state_led_red);
                Serial.println("Red LED");
                break;
            }

            case IR_BUTTON_2: {
                state_led_green = (state_led_green == LOW) ? HIGH : LOW;
                digitalWrite(LED_GREEN, state_led_green);
                Serial.println("Green LED");
                break;
            }

            default: {
                digitalWrite(LED_RED, LOW);
                digitalWrite(LED_GREEN, LOW);
                Serial.println("Try again");
            }
        }
    }
}
