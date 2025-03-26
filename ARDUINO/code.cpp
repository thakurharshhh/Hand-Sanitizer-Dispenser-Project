// Arduino Code
// Constants for the ultrasonic sensor
const int trigPin = 7;
const int echoPin = 6;
const int motorPin = 9;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  if (distance > 0 && distance <= 10) {
    digitalWrite(motorPin, HIGH);
    Serial.println("Hand detected, motor ON");
  } else {
    digitalWrite(motorPin, LOW);
    Serial.println("No hand detected, motor OFF");
  }
  delay(500);
}
