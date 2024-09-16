/*
 Stepper Motor - Constant Revolution
 Motor will move one step at a time
 All steps should move in the correct direction if wiring is correct
 The motor is attached to digital pins 4-7 (in signed magnitude mode of Arduino 2A shield)
| DIR2 |  7 |
| EN2  |  6 |
| EN1  |  5 |
| DIR1 |  4 |
 */

#include <Stepper.h>

const int stepsPerRevolution = 200;   //number of steps per revolution for your motor
Stepper myStepper(stepsPerRevolution, 4, 6, 5, 7); // initialize the stepper library
int stepCount = 0;         // number of steps the motor has taken

void setup() {
  Serial.begin(9600); // initialize the serial port:
}

void loop() {
  clockwise(); //comment and uncomment based on direction
  //counterclockwise(); 
  Serial.print("steps:");
  Serial.println(stepCount);
  stepCount++;
  delay(500);
}

void clockwise(){ // step one revolution  in one direction:
  Serial.println("clockwise");
  myStepper.step(1);
}

void counterclockwise(){ // step one revolution in the other direction
  Serial.println("counterclockwise");
  myStepper.step(-1);
}

