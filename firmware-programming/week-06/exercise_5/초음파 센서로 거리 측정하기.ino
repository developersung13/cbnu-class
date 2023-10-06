#define PIN_TRIG 11
#define PIN_ECHO 12

long duration;
int distance;

void setup() {
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
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
}