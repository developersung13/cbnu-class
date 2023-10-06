#define PIN_ECHO 11
#define PIN_TRIG 12
#define LED_RED 4

long duration;
int distance;

void setup() {
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  pinMode(LED_RED, OUTPUT);
  Serial.begin(9600);
  Serial.println("Ultrasonic Sensor Test!");
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

  if (distance < 40) {
    digitalWrite(LED_RED, HIGH);
    Serial.println("OK!");
  } else {
    digitalWrite(LED_RED, LOW);
    Serial.println("What?");
  }
}