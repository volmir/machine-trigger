

#define sensorPin 2

#define relay1Pin 5
#define relay2Pin 6

boolean sensorFlag = true;
boolean sensor = false;
unsigned long sensorTimer;


void setup() {
  pinMode(sensorPin, INPUT_PULLUP);

  pinMode(relay1Pin, OUTPUT);
  pinMode(relay2Pin, OUTPUT);
  
  digitalWrite(relay1Pin, HIGH);
  digitalWrite(relay2Pin, HIGH);
}

void loop() {
  sensor = digitalRead(sensorPin);

  if (sensor && millis() - sensorTimer > 500) {
    sensorFlag = !sensorFlag;
    sensorTimer = millis();

    if (sensorFlag) {
      digitalWrite(relay1Pin, LOW);
    } else {
      digitalWrite(relay1Pin, HIGH);
    }
    delay(100);
    if (sensorFlag) {
      digitalWrite(relay2Pin, HIGH);
    } else {
      digitalWrite(relay2Pin, LOW);
    }
  }
}
