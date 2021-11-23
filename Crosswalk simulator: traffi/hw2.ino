const int buttonPin = 2;
const int buzzPin = 8;
const int buzzTone = 5000;

const int ledPinCarRed = 5;
const int ledPinCarYellow = 4;
const int ledPinCarGreen = 3;

const int ledPinPersonRed = 11;
const int ledPinPersonGreen = 12;

bool buttonState = HIGH;
bool previousState = HIGH;

bool ledStateCarRed = LOW;
bool ledStateCarYellow = LOW;
bool ledStateCarGreen = HIGH;

bool ledStatePersonRed = HIGH;
bool ledStatePersonGreen = LOW;

unsigned int waitState1toState2 = 10000;
unsigned int buttonPressState1 = 0;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); 
  pinMode(ledPinCarGreen, OUTPUT); 
  pinMode(ledPinCarYellow, OUTPUT);
  pinMode(ledPinCarRed, OUTPUT);
  pinMode(ledPinPersonGreen, OUTPUT);
  pinMode(ledPinPersonRed, OUTPUT);
  Serial.begin(9600);

}

void state1() {
  ledStateCarGreen = HIGH;
  ledStateCarYellow = LOW; 
  ledStateCarRed = LOW;
  ledStatePersonGreen = LOW; 
  ledStatePersonRed = HIGH;
  showLeds();
}

void state2() {
  buttonPressState1 = millis();
  while(millis() - buttonPressState1 < waitState1toState2){
    
  }
  delay(2000);
  ledStateCarGreen = LOW; 
  ledStateCarYellow = HIGH;
  showLeds();
  delay(3000);
}

void state3() {
  
  ledStateCarYellow = LOW; 
  ledStateCarRed = HIGH;
  ledStatePersonRed = LOW; 
  ledStatePersonGreen = HIGH;
  showLeds();
  for (int i = 1; i <= 3; i++) {
    tone(buzzPin, buzzTone);
    delay(1200);
    noTone(buzzPin);
    delay(1200);
  }
}

void state4() {
  for (int i = 1; i <= 5; i++) {
    ledStatePersonGreen = HIGH; 
    showLeds(); 
    tone(buzzPin, buzzTone);
    delay(250);
    ledStatePersonGreen = LOW; 
    showLeds(); 
    noTone(buzzPin);
    delay(250); 
  }
}

bool reading = HIGH;
bool previousReading = HIGH;
unsigned long lastDebounceTime = 0;
unsigned long debounceInterval = 50;

void loop() {
 reading = digitalRead(buttonPin);
 if(reading != previousReading) {
  lastDebounceTime = millis();
 }
 if(millis() - lastDebounceTime > debounceInterval){
  if(reading != buttonState) {
    buttonState = reading;
    if(buttonState == HIGH){
      //ledState =! ledState;
      state2();
      state3();
      state4();
      state1();
    }
  }
 }
 previousReading = reading;


// Serial.println(buttonState);
 
}

void showLeds() {
  digitalWrite(ledPinCarGreen, ledStateCarGreen); 
  digitalWrite(ledPinCarYellow, ledStateCarYellow); 
  digitalWrite(ledPinCarRed, ledStateCarRed); 
  digitalWrite(ledPinPersonGreen, ledStatePersonGreen); 
  digitalWrite(ledPinPersonRed, ledStatePersonRed);
}
