int pinX = A4;
int pinY = A5;
int pinSW = 2;

bool moveUpDown = false;

bool joyMovedX = LOW;
bool joyMovedY = LOW;
bool readingSW = LOW;
int xValue = 0;
int yValue = 0;
bool dpState = LOW;
bool state = HIGH;
bool buttonState = LOW;
int lastButtonState = LOW;

int minThreshold = 350;
int maxThreshold = 700;

unsigned int lastDebounceTime = 0;
unsigned int debounceDelay = 50;

int counterLoop = 0; 


int myNumber[4] = {
   0, 0, 0, 0
};

int actPoz = 3; 

// ST_CP
const int latchPin = 11;
// SH_CP
const int clockPin = 10;
// DS
const int dataPin = 12;

int digitArray[16] = {
//A B C D E F G DP 
  B11111100, // 0
  B01100000, // 1
  B11011010, // 2
  B11110010, // 3
  B01100110, // 4
  B10110110, // 5
  B10111110, // 6
  B11100000, // 7
  B11111110, // 8
  B11110110, // 9
  B11101110, // A
  B00111110, // b
  B10011100, // C
  B01111010, // d
  B10011110, // E
  B10001110  // F
};

int digitPointArray[16] = {
//A B C D E F G DP 
  B11111101, // 0
  B01100001, // 1
  B11011011, // 2
  B11110011, // 3
  B01100111, // 4
  B10110111, // 5
  B10111111, // 6
  B11100001, // 7
  B11111111, // 8
  B11110111, // 9
  B11101111, // A
  B00111111, // b
  B10011101, // C
  B01111011, // d
  B10011111, // E
  B10001111  // F
};

const int segD1 = 7;
const int segD2 = 6;
const int segD3 = 5;
const int segD4 = 4;


const int displayCount = 4;

int displayDigits[] = {
  segD1, segD2, segD3, segD4
};


void setup (){
  // Setup pins as Outputs
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);

  pinMode(pinY, INPUT);
  pinMode(pinX, INPUT);
  pinMode(pinSW, INPUT_PULLUP);

  for (int i = 0; i < displayCount; i++) {
    pinMode(displayDigits[i], OUTPUT);
    digitalWrite(displayDigits[i], LOW);
  }
  
  Serial.begin(9600);
}

void movePoint() {
  // mutarile pentru punct

  if(yValue > maxThreshold && joyMovedY == false){
    actPoz++;
    joyMovedY = true;
  }

  if(yValue < minThreshold && joyMovedY == false){
    actPoz--;
    joyMovedY = true;
  }

  if (actPoz > 3)
    actPoz = 0;
  if (actPoz < 0)
    actPoz = 3;

  if(yValue > minThreshold && yValue < maxThreshold)
    joyMovedY = false;
}

void moveDigit() {
  // mutarile pentru fiecare cifra

  if(xValue > maxThreshold && joyMovedX == false){
    myNumber[actPoz]++; 
    myNumber[actPoz] %= 10; 
    joyMovedX = true;
  }

  if(xValue < minThreshold && joyMovedX == false){
    --myNumber[actPoz];
    myNumber[actPoz] += 10;  
    myNumber[actPoz] %= 10; 
    joyMovedX = true;
  }

  if(xValue > minThreshold && xValue < maxThreshold)
    joyMovedX = false;
}

void solve() {

  if (readingSW != lastButtonState) {
    lastDebounceTime = millis(); 
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (readingSW != buttonState) {
      buttonState = readingSW; 
      if (buttonState == LOW) {
        moveUpDown = !moveUpDown; 
      }
    }
  }

  lastButtonState = readingSW;  
  
  writeMyNumber();

  if (moveUpDown == false)
    movePoint();
  else
    moveDigit();
}

void loop(){
  for(int i = 0; i < displayCount; i++){
    digitalWrite(displayDigits[i], HIGH);
  }

  ++counterLoop; 

  xValue = analogRead(pinX);
  yValue = analogRead(pinY);
  readingSW = digitalRead(pinSW);

  solve();
}

void writeMyNumber(){
  for (int displayDigit = 3; displayDigit >= 0; displayDigit--) {
    showDigit(displayDigit);
    
    if (actPoz == displayDigit){ 
      if (moveUpDown == true && counterLoop % 4 == 0)
        writeReg(digitArray[myNumber[displayDigit]]);
      else
        writeReg(digitPointArray[myNumber[displayDigit]]);
    }
    else 
      writeReg(digitArray[myNumber[displayDigit]]);
       
    delay(8);
  }
}

void showDigit(int digit){
  for(int i = 0; i < displayCount; i++){
    digitalWrite(displayDigits[i], HIGH);
  }
  
  digitalWrite(displayDigits[digit], LOW);
}

void writeReg(int digit) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, digit);
  digitalWrite(latchPin, HIGH); 
}
