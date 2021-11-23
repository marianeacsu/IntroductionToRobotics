# IntroductionToRobotics
### [Homework 0](https://github.com/marianeacsu/IntroductionToRobotics/tree/main/Lab1)
### [Homework 1](https://github.com/marianeacsu/IntroductionToRobotics/tree/main/hw2)

#### 1. Components

RBG led (1 minimum), potentiometers (3 minimum), 3 resistors and wires (per logic)

#### 2.Task Requirements

- Use a separat potentiometer in controlling each of the color of the RGB led (Red, Green and Blue)
- The control must be done with digital electronics(aka you must read the value of the potentiometer with Arduino
 and write a mapped value to each of the pins connected to the led.)

#### 3.Picture of the setup

![rgb resistors foto](https://user-images.githubusercontent.com/58784210/139128684-a29bb2c6-57e0-4284-a07e-b6df601194fd.jpeg)

#### 4.Video 

https://www.youtube.com/watch?v=pqcDeQspXZg


#### [5.Code](https://github.com/marianeacsu/IntroductionToRobotics/blob/main/hw2/try.ino)

### [Homework 2]

#### 1. Components

 5 LEDs, 1 button, 1 buzzer, resistors and wires (per logic)
 
#### 2. Task Requirements

Building the traffic lights for a crosswalk.You will use 2 LEDs to represent the traffic lights for people (red and green) and 3 LEDs to represent the traffic lights for cars (red, yellow and green). See the states it needs to go through: 

State 1(default, reinstated after state 4 ends): 
- green light for cars, red  light for people, no sounds   
- duration: indefinite, changed by pressing the button

State 2(initiated by counting down 10 seconds after a button press):
- the light should be yellow for cars, red for people and no sounds
- duration: 3 seconds

State 3(initiated after state 2 ends): 
- red for cars, green for people and a beeping sound from the buzzer at a constant interval  
- duration: 10 seconds

State 4(initiated after state 3 ends):
- red for cars, blinking green for people and a beeping sound from the buzzer, at a constant interval, faster than the beeping in state 3  
- This state should last 5 seconds

#### 3. Picture of the setup

![hw2](https://user-images.githubusercontent.com/58784210/143010832-551d45e0-bd72-42ae-9e66-19d622f3793a.jpeg)

#### 4. Video

https://www.youtube.com/watch?v=qpg_JbmJouc

#### [5. Code]


### [Homework 4](https://github.com/marianeacsu/IntroductionToRobotics/tree/main/hw4)

#### 1.Components

A joystick, a 4 digit 7-segment display, a 74hc595 shift register

#### 2.Task Requirements

First state:
- you can use a joystick axis to cycle through the 4digits; using the other axis does nothing. A blinking decimal point shows the current digit position. When pressing the button (must use interruptfor maximum points!), you lock in on the selected digit and enter thesecond state

Second state:
- the decimal point stays always on, no longer blinking and you can no longer use the axis to cycle through the 4 digits. Instead, using the other axis, you can increment on decrement the number on the current digit. Pressing the button again returns you to the previous state. For bonus, save the last value in eeprom and load it when starting arduino. Also, keep in mind that when changing the number, you must increment it for each joystick movement-it should not work continuosly increment if you keep the joystick in one position.

#### 3.Picture of the setup

![WhatsApp Image 2021-11-17 at 20 03 16](https://user-images.githubusercontent.com/58784210/142263466-168764a2-6da4-4789-b06e-9eff903f62a7.jpeg)

#### 4.Video

https://www.youtube.com/watch?v=5bbYXtheYTQ

#### [5.Code](https://github.com/marianeacsu/IntroductionToRobotics/blob/main/hw4/hw4.ino)


