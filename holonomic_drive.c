// Copyright Stuy Fission 310
/**
 * Authored by Alvin Lin (alvin.lin@stuypulse.com)
 * http://omgimanerd.github.io
 * http://310fission.com
 * This file is teleop program for our holonomic drivetrain prototype.
 */
#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     Q1,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     Q2,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     Q3,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     Q4,            tmotorTetrix, openLoop)

#include "JoystickDriver.c"

task main {
	int x1, y1, x2, y2;
	while (true){
		// Update the values of the variables storing the joystick positions.
		getJoystickSettings(joystick);
	 	x1 = joystick.joy1_x1;
		y1 = joystick.joy1_y1;
		x2 = joystick.joy1_x2;
	 	y2 = joystick.joy1_y2;

 		int radius = 25;
	 	// Scaling since motors go from -100 -> +100 and joysticks go from -128
	 	// to +128.
 		x2 /= 1.7;
 		y2 /= 1.7;

 		// The motors will not move if the joystick has not been pushed a
 		// a sufficient distance.
   	if (abs(x1) < radius) {
			x1 = 0;
		}
		if (abs(y1) < radius) {
    	y1 = 0;
		}
		if (abs(x2) < radius) {
			x2 = 0;
		}
		if (abs(y2) < radius) {
			y2 = 0;
		}

		// Sets the power of the motor accordingly.
		motor[Q1] = (  y2 - x2  ) - x1;
		motor[Q2] = ( -y2 - x2  ) - x1;
		motor[Q3] = ( -y2 + x2  ) - x1;
		motor[Q4] = (  y2 + x2  ) - x1;

		// Outputs the joystick values to the screen.
		nxtDisplayString(2, "X1: %i", x1);
		nxtDisplayString(2, "X1: %i", x1);
		nxtDisplayString(2, "X1: %i", x1);
		nxtDisplayString(2, "X1: %i", x1);
	}
}
