#include <IRremote.h>

#define IR_RECEIVE_PIN 8
#define IR_BUTTON_1 69
#define IR_BUTTON_2 70
#define IR_BUTTON_3 71

void setup() {
    Serial.begin(9600);
    IrReceiver.begin(IR_RECEIVE_PIN);
}

void loop() {
    if (IrReceiver.decode()) {
        IrReceiver.resume();
        int command = IrReceiver.decodedIRData.command;
        switch (command) {
            case IR_BUTTON_1: {
                Serial.println("You are pressed button no.1");
                break;
            }

            case IR_BUTTON_2: {
                Serial.println("You are pressed button no.2");
                break;
            }

            case IR_BUTTON_3: {
                Serial.println("You are pressed button no.3");
                break;
            }

            default: {
                Serial.println("Try again");
            }
        }
    }
}
