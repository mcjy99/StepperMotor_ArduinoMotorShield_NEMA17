/*
 Stepper Motor - One Revolution
 Motor will first turn clockwise one rev, then counterclockwise one rev, and so on
 The motor is attached to digital pins 4-7 (in signed magnitude mode of Arduino 2A shield)
| DIR2 |  7 |
| EN2  |  6 |
| EN1  |  5 |
| DIR1 |  4 |
*/

#include <Stepper.h>

#define SPEED 60 //motor speed
const int stepsPerRevolution = 200;  // number of steps per revolution (depends on motor)

// initialize the stepper library on pins 4 through 7:
Stepper myStepper(stepsPerRevolution, 4, 6, 5, 7);

void setup() {
  myStepper.setSpeed(SPEED); //set the speed
  Serial.begin(9600); // initialize the serial port
}

void loop() {
  clockwise();
  delay(2000);
  counterclockwise();
  delay(2000);
}

void clockwise(){ // step one revolution  in one direction:
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
}

void counterclockwise(){ // step one revolution in the other direction
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
}

