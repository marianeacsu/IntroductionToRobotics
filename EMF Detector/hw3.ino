const int pinA = 2;
const int pinB = 3;
const int pinC = 4;
const int pinD = 5;
const int pinE = 6;
const int pinF = 7;
const int pinG = 8;
const int pinDP = 9;
bool decimalpointState = LOW;

const int buzzPin = 12;
int buzzTone = 5000;

const int readingsCount = 20;
int readings[readingsCount];  
int index = 0;                           
int total = 0;
int average = 0;       

int limit = 850; 
int antenaPin = A5; 
int antenaValue = 0;

const int segSize = 8;
const int noOfDigits = 10;


int segments[segSize] = {
  pinA, pinB, pinC, pinD, pinE, pinF, pinG, pinDP
};

bool digitMatrix[noOfDigits][segSize - 1] = {
// a  b  c  d  e  f  g
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}  // 9
};

void displayNumber(byte digit, bool decimalPoint) {
  for (int i = 0; i < segSize - 1; i++) {
    digitalWrite(segments[i], digitMatrix[digit][i]);
  }
  digitalWrite(pinDP, decimalPoint);
  
  buzzTone = digit * 1000;
  tone(buzzPin, buzzTone, 20);
}

void setup() {
  pinMode(antenaPin,INPUT);
  pinMode(buzzPin,OUTPUT);
  
  for (int i = 0; i < segSize; i++) {
    pinMode(segments[i], OUTPUT);
  }
  
  for (int i = 0; i < readingsCount; i++)
    readings[i] = 0;   
  
  Serial.begin(9600);
}


void loop(){
  antenaValue = analogRead(antenaPin);
  if(antenaValue >= 1){
    antenaValue = constrain(antenaValue, 0, limit);  
    antenaValue = map(antenaValue, 0, limit, 1, noOfDigits - 1);;
    total -= readings[index];
    readings[index] = antenaValue;
    total += antenaValue;
    index++;
    //Serial.println(total);
    average = total / readingsCount;
    if(index >= readingsCount){ 
      index = 0;
    }
    Serial.println(average);
    displayNumber(average, decimalpointState);
    delay(100);
  }
}
