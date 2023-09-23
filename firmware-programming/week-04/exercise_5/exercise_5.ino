#include <Servo.h>
#include <SoftwareSerial.h>
#define BTtx 10
#define BTrx 11
#define LED_Red 13

SoftwareSerial BT(BTtx, BTrx); 

Servo myservo;
int pinPoten = A0;
int val;


void setup() {
  BT.begin(9600);
  Serial.begin(9600);
  myservo.attach(9);
  pinMode(LED_Red, OUTPUT);
}

int data = 0;

void loop() {
  if(BT.available() > 0)
    data = BT.read();
  
  Serial.println(data);
  myservo.write(data);
  delay(20);

  if (data >= 90)
    digitalWrite(LED_Red, HIGH);
  else
    digitalWrite(LED_Red, LOW);
}