/*
 Stepper Motor - Constant Revolution
 Motor will constantly revolve in a certain direction
 Used to test motor connection
 The motor is attached to digital pins 4-7 (in signed magnitude mode of Arduino 2A shield)
| DIR2 |  7 |
| EN2  |  6 |
| EN1  |  5 |
| DIR1 |  4 |
 */

#include <Stepper.h>

const int stepsPerRevolution = 200;  //number of steps per revolution for your motor

// initialize the stepper library
Stepper myStepper(stepsPerRevolution, 4, 6, 5, 7); 

void setup() {
  // set the speed at 60 rpm:
  myStepper.setSpeed(60);
  Serial.begin(9600);
}

void loop() { //comment and uncomment based on direction
  clockwise();
  //counterclockwise();
}

void clockwise(){ // step one revolution  in one direction:
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
}

void counterclockwise(){ // step one revolution in the other direction
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
}

