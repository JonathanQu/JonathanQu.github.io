#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     Q1,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     Q2,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     Q3,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     Q4,            tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"

int nullRad = 50;

int x1 = 0;
int y1 = 0;
int x2 = 0;

bool horizontalInactive;
bool verticalInactive;
bool preventsConflict = true;

int scale(int scaleThis) {
	return ((scaleThis - nullRad) * (100/(128 - nullRad)));
}

void goNorth() {
	motor[Q1] = scale(y1);
	motor[Q2] = -scale(y1);
	motor[Q3] = scale(y1);
	motor[Q4] = -scale(y1);
}
void goSouth() {
	motor[Q1] = -scale(y1);
	motor[Q2] = scale(y1);
	motor[Q3] = -scale(y1);
	motor[Q4] = scale(y1);
}
void goWest() {
	motor[Q1] = scale(x1);
	motor[Q2] = scale(x1);
	motor[Q3] = -scale(x1);
	motor[Q4] = -scale(x1);
}
void goEast() {
	motor[Q1] = -scale(x1);
	motor[Q2] = -scale(x1);
	motor[Q3] = scale(x1);
	motor[Q4] = scale(x1);
}

void spinClockwise() {
	motor[Q1] = scale(x2);
	motor[Q2] = scale(x2);
	motor[Q3] = scale(x2);
	motor[Q4] = scale(x2);
}
void spinCounterClockwise() {
	motor[Q1] = -scale(x2);
	motor[Q2] = -scale(x2);
	motor[Q3] = -scale(x2);
	motor[Q4] = -scale(x2);
}

task main() {
	outer:
	while (true) {
		getJoystickSettings(joystick);
		x1 = joystick.joy1_x1;
		y1 = joystick.joy1_y1;
		x2 = joystick.joy1_x2;

		//energy conservation
		if (abs(x1) <= nullRad && abs(y1) <= nullRad
			&& abs(x2) <= nullRad) {wait1Msec(25); goto outer;} //if both joysticks inactive, waits 25
	//msecs and then goes back to beginning of while (true) loop

		//x1, y1: movement
		if (preventsConflict) { //prevents robot from attempting to move and rotate simultaneously
		if (abs(x1) <= nullRad) {
			x1 = 0;
			horizontalInactive = true;
		}
		if (abs(y1) <= nullRad) {
			y1 = 0;
			verticalInactive = true;
		}

		if (horizontalInactive && verticalInactive) { //if left joystick inactive, sets the stage for right joystick
			preventsConflict = false;
		}

		if (x1 > nullRad) {
			goEast();
			if (y1 > nullRad) {goNorth();}
			if (y1 < -nullRad) {goSouth();}
		}
		if (x1 < -nullRad) {
			goWest();
			if (y1 > nullRad) {goNorth();}
			if (y1 < -nullRad) {goSouth();}
		}
		}
		//end movement

		//x2, y2: rotation
		if (!preventsConflict) { //makes sure robot isn't already moving
		if (abs(x2) <= nullRad) { //checks if right joystick inactive
			preventsConflict = true; //sets the stage for left joystick to control
		}
		else if (x2 > nullRad) {
			spinClockwise();
		}
		else if (x2 < -nullRad) {
			spinCounterClockwise();
		}
		}
		//end rotation
	}
}
