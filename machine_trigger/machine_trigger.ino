

#define sensorPin 2
#define motionPin 3

#define relay1Pin 5
#define relay2Pin 11

boolean sensorState = true;
boolean sensor = false;
unsigned long sensorTimer;

boolean motionState = false;  
boolean motionButton = false;
unsigned long motionTimer;


void setup() {
  pinMode(sensorPin, INPUT_PULLUP);
  pinMode(motionPin, INPUT_PULLUP);

  pinMode(relay1Pin, OUTPUT);
  pinMode(relay2Pin, OUTPUT);
  
  digitalWrite(relay1Pin, LOW);
  digitalWrite(relay2Pin, LOW);

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  motionButton = digitalRead(motionPin);  
  if (!motionButton && millis() - motionTimer > 300) {
    motionTimer = millis();
    motionState = !motionState; 
  }
  
  if (motionState) { 
    proceedMotion(); 
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(relay1Pin, LOW);
    digitalWrite(relay2Pin, LOW);
    digitalWrite(LED_BUILTIN, LOW);    
  }
}

void proceedMotion() {
  sensor = digitalRead(sensorPin);  

  if (sensor && millis() - sensorTimer > 800) {
    sensorState = !sensorState;
    sensorTimer = millis();

    if (sensorState) {
      digitalWrite(relay1Pin, LOW);
    } else {
      digitalWrite(relay1Pin, HIGH);
    }
    delay(100);
    if (sensorState) {
      digitalWrite(relay2Pin, HIGH);
    } else {
      digitalWrite(relay2Pin, LOW);
    }
  }  
}
