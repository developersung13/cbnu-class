#include <IRremote.h>
#include <Servo.h>

#define IR_RECEIVE_PIN 8
#define IR_BUTTON_1 69
#define IR_BUTTON_2 70
#define IR_BUTTON_3 71
#define IR_BUTTON_4 68
#define IR_BUTTON_5 64
#define IR_BUTTON_6 67
#define IR_BUTTON_7 7
#define LED_RED_PIN 12
#define LED_GREEN_PIN 11
#define LED_BLUE_PIN 10

byte state_led_red = LOW;
byte state_led_green = LOW;


void setup() {
    Serial.begin(9600);
    IrReceiver.begin(IR_RECEIVE_PIN);
    pinMode(LED_RED_PIN, OUTPUT);
    pinMode(LED_GREEN_PIN, OUTPUT);
    pinMode(LED_BLUE_PIN, OUTPUT);
}

void loop() {
    if (IrReceiver.decode()) {
        IrReceiver.resume();
        int command = IrReceiver.decodedIRData.command;
        switch (command) {
            case IR_BUTTON_1: {
                RGB_Color(255, 0, 0);
                Serial.println("1");
                break;
            }

            case IR_BUTTON_2: {
                RGB_Color(0, 255, 0);
                Serial.println("2");
                break;
            }

            case IR_BUTTON_3: {
                RGB_Color(0, 0, 255);
                Serial.println("3");
                break;
            }

            case IR_BUTTON_4: {
                RGB_Color(255, 255, 0);
                Serial.println("4");
                break;
            }

            case IR_BUTTON_5: {
              RGB_Color(255, 0, 255);
                Serial.println("5");
                break;
            }

            case IR_BUTTON_6: {
              RGB_Color(0, 255, 255);
                Serial.println("6");
                break;
            }

            case IR_BUTTON_7: {
              RGB_Color(255, 255, 255);
                Serial.println("7");
                break;
            }

            default: {
                RGB_Color(0, 0, 0);
                Serial.println("Try again");
            }
        }
    }
}

void RGB_Color(int led_red_val, int led_green_val, int led_blue_val) {
  analogWrite(LED_RED_PIN, led_red_val);
  analogWrite(LED_GREEN_PIN, led_green_val);
  analogWrite(LED_BLUE_PIN, led_blue_val);
}