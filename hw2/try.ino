const int ledPinRed = 11;
const int ledPinGreen = 10;
const int ledPinBlue = 9;

const int potPinRed = A2;
const int potPinGreen = A3;
const int potPinBlue = A0;

int potValueRed = 0; 
int potValueGreen = 0; 
int potValueBlue = 0; 

int brightnessRed = 0;
int brightnessGreen = 0;
int brightnessBlue = 0;

const int maxValue = 1023;
const int maxValue1 = 255;

void setup() {
  pinMode(ledPinGreen, OUTPUT);
  pinMode(ledPinBlue, OUTPUT);
  pinMode(ledPinRed, OUTPUT);
  pinMode(potPinGreen, INPUT); 
  pinMode(potPinBlue, INPUT);
  pinMode(potPinRed, INPUT); 
}

void loop() {
  potValueGreen = analogRead(potPinGreen);
  potValueBlue = analogRead(potPinBlue);
  potValueRed = analogRead(potPinRed);

  brightnessRed = map(potValueRed, 0, maxValue, 0, maxValue1);
  brightnessBlue = map(potValueBlue, 0, maxValue, 0, maxValue1);
  brightnessGreen = map(potValueGreen, 0, maxValue, 0, maxValue1);
  
  analogWrite(ledPinRed, brightnessRed);
  analogWrite(ledPinGreen, brightnessGreen);
  analogWrite(ledPinBlue, brightnessBlue);
}
