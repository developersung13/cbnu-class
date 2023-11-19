#include <IRremote.h>
#include <Servo.h>

#define IR_RECEIVE_PIN 8
#define IR_BUTTON_UP 24
#define IR_BUTTON_OK 28
#define IR_BUTTON_LEFT 8
#define IR_BUTTON_RIGHT 90

Servo myservo;

int pin_servo = 9;

void setup() {
    Serial.begin(9600);
    IrReceiver.begin(IR_RECEIVE_PIN);
    myservo.attach(pin_servo);
}

void loop() {
    if (IrReceiver.decode()) {
        IrReceiver.resume();
        int command = IrReceiver.decodedIRData.command;
        switch (command) {
            case IR_BUTTON_UP: {
                myservo.write(90);
                Serial.println("UP");
                break;
            }

            case IR_BUTTON_LEFT: {
                myservo.write(0);
                Serial.println("LEFT");
                break;
            }

            case IR_BUTTON_RIGHT: {
                myservo.write(180);
                Serial.println("RIGHT");
                break;
            }

            case IR_BUTTON_OK: {
              Serial.println("OK");
                myservo.write(0);
                delay(500);
                myservo.write(180);
                delay(500);
                myservo.write(0);
                delay(500);
                myservo.write(90);
                delay(500);
                break;
            }

            default: {
                Serial.println("Try again");
            }
        }
    }
}
