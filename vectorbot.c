#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Hubs,  S2, HTMotor,  HTMotor,  none,     none)
#pragma config(Hubs,  S3, HTServo,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Sensor, S3,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     frontLeft,      tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     ledSpiral,     tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     frontRight,     tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     ledUnderlighting, tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S2_C1_1,     backLeft,     tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S2_C1_2,     ledSign,       tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S2_C2_1,     backRight,    tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S2_C2_2,     ledBox,        tmotorNormal, openLoop)
#pragma config(Servo,  srvo_S3_C1_1,    frontRightS,           tServoStandard)
#pragma config(Servo,  srvo_S3_C1_2,    frontLeftS,            tServoStandard)
#pragma config(Servo,  srvo_S3_C1_3,    backLeftS,             tServoStandard)
#pragma config(Servo,  srvo_S3_C1_4,    backRightS,               tServoStandard)
#pragma config(Servo,  srvo_S3_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S3_C1_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int x1 = 0;
int y1 = 0;
int x2 = 0;

int ledSpiralOn = -1;
int ledBoxOn = -1;
int ledUnderlightingOn = -1;
int ledSignOn = -1;

bool rotating = false;

//bool movingForwards;

#include "JoystickDriver.c"

task main(){

	servoChangeRate[frontRightS] = 0;
	servoChangeRate[frontLeftS] = 0;
	servoChangeRate[backLeftS] = 0;
	servoChangeRate[backRightS] = 0;

  while(true){
    getJoystickSettings(joystick);

  x1 = joystick.joy1_x1;
  y1 = joystick.joy1_y1;
 	x2 = joystick.joy1_x2;

 	if ((x1 == -128) && (y1 == -128)){
 	  x1 = -127;
 	  y1 = -126;
 	}

 	if (rotating == false){
 	//arctan drive
 	servo[frontRightS] = 128 * (1 + atan(y1/x1)/PI);
 	servo[frontLeftS] = 128 * (1 + atan(y1/x1)/PI);
	servo[backLeftS] = 128 * (1 + atan(y1/x1)/PI);
	servo[backRightS] = 128 * (1 + atan(y1/x1)/PI);
 	/*if (y1 > 20){
 		motor[frontRight] = sqrt( x1*x1 + y1*y1);
		motor[frontLeft] = -sqrt( x1*x1 + y1*y1);
		motor[backLeft] = -sqrt( x1*x1 + y1*y1);
		motor[backRight] = sqrt( x1*x1 + y1*y1);
	}
	else if (y1 < 20){
		motor[frontRight] = -sqrt( x1*x1 + y1*y1);
		motor[frontLeft] = sqrt( x1*x1 + y1*y1);
		motor[backLeft] = sqrt( x1*x1 + y1*y1);
		motor[backRight] = -sqrt( x1*x1 + y1*y1);
	}
	else if (abs(x1) > 20) {
		motor[frontRight] = x1;
		motor[frontLeft] = -x1;
		motor[backLeft] = -x1;
		motor[backRight] = x1;
	}
	else {
		motor[frontRight] = 0;
		motor[frontLeft] = 0;
		motor[backLeft] = 0;
		motor[backRight] = 0;
	}*/




		//if (y1 > 10){
		/*servo[frontRightS] = 255 - (x1 + 128);
		servo[frontLeftS] = 255 - (x1 + 128) ;
		servo[backLeftS] = 255 - (x1 + 128) ;
		servo[backRightS] = 255 - (x1 + 128) ;
		motor[frontRight] = sqrt( x1*x1 + y1*y1);
		motor[frontLeft] = -sqrt( x1*x1 + y1*y1);
		motor[backLeft] = -sqrt( x1*x1 + y1*y1);
		motor[backRight] = sqrt( x1*x1 + y1*y1);
		movingForwards = true;
		}
		else if (y1 < -10){
	  servo[frontRightS] = (x1 + 128) ;
		servo[frontLeftS] = (x1 + 128) ;
		servo[backLeftS] = (x1 + 128) ;
		servo[backRightS] = (x1 + 128) ;
		motor[frontRight] = -sqrt( x1*x1 + y1*y1);
		motor[frontLeft] = sqrt( x1*x1 + y1*y1);
		motor[backLeft] = sqrt( x1*x1 + y1*y1);
		motor[backRight] = -sqrt( x1*x1 + y1*y1);
		movingForwards = false;
	}
		else if (abs(x1) > 10) {
		  if (movingForwards) {
				servo[frontRightS] = 255 - (x1 + 128);
				servo[frontLeftS] = 255 - (x1 + 128) ;
				servo[backLeftS] = 255 - (x1 + 128) ;
				servo[backRightS] = 255 - (x1 + 128) ;
				motor[frontRight] = sqrt( x1*x1 + y1*y1);
				motor[frontLeft] = -sqrt( x1*x1 + y1*y1);
				motor[backLeft] = -sqrt( x1*x1 + y1*y1);
				motor[backRight] = sqrt( x1*x1 + y1*y1);
		}
		  else {
				servo[frontRightS] = (x1 + 128) ;
				servo[frontLeftS] = (x1 + 128) ;
				servo[backLeftS] = (x1 + 128) ;
				servo[backRightS] = (x1 + 128) ;
				motor[frontRight] = -sqrt( x1*x1 + y1*y1);
				motor[frontLeft] = sqrt( x1*x1 + y1*y1);
				motor[backLeft] = sqrt( x1*x1 + y1*y1);
				motor[backRight] = -sqrt( x1*x1 + y1*y1);
		  }/*
		servo[frontRightS] = 255 - (x1 + 128);
		servo[frontLeftS] = 255 - (x1 + 128) ;
		servo[backLeftS] = 255 - (x1 + 128) ;
		servo[backRightS] = 255 - (x1 + 128) ;
		motor[frontRight] = abs(x1);
		motor[frontLeft] = -abs(x1);
		motor[backLeft] = -abs(x1);
		motor[backRight] = abs(x1);
		}
		else {
		motor[frontRight] = 0;
		motor[frontLeft] = 0;
		motor[backLeft] = 0;
		motor[backRight] = 0;
	}
}*/
}

  if (abs(x2) > 20) {
    rotating = true;
		servo[frontRightS] = 192 ;
		servo[frontLeftS] = 64 ;
		servo[backLeftS] = 192 ;
		servo[backRightS] = 64 ;

		motor[frontRight] = -x2;
		motor[frontLeft] = -x2;
		motor[backLeft] = -x2;
		motor[backRight] = -x2;
  }
  else {
    rotating = false;
  }

	//led's

	if (joy1Btn(1) == 1) {
	  ledBoxOn = ledBoxOn * -1;
	  wait1Msec(100);
	}
	if (joy1Btn(2) == 1) {
	  ledSpiralOn = ledSpiralOn * -1;
	  wait1Msec(100);
	}
	if (joy1Btn(3) == 1) {
	  ledUnderlightingOn = ledUnderlightingOn * -1;
	  wait1Msec(100);
	}
	if (joy1Btn(4) == 1) {
	  ledSignOn = ledSignOn * -1;
	  wait1Msec(100);
	}
	if ((joy1Btn(5) == 1) || (joy1Btn(6) == 1)) {
	  ledBoxOn = -1;
	  ledSpiralOn = -1;
	  ledUnderlightingOn = -1;
	  ledSignOn = -1;
	}

	if (ledSignOn > 0){
	  motor[ledSign] = 50;
	}
	else {
	  motor [ledSign] = 0;
	}
	if (ledSpiralOn > 0){
	  motor[ledSpiral] = 50;
	}
	else {
	  motor [ledSpiral] = 0;
	}
		if (ledUnderlightingOn > 0){
	  motor[ledUnderlighting] = 50;
	}
	else {
	  motor [ledUnderlighting] = 0;
	}
		if (ledBoxOn > 0){
	  motor[ledBox] = 50;
	}
	else {
	  motor [ledBox] = 0;
	}


  }
}
