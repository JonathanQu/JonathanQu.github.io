#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     motorF,        tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorG,        tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     motorH,        tmotorNone, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     motorI,        tmotorNone, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include <JoystickDriver.c>

task main() {
  while(1) {
    getJoystickSettings(joystick);
    motor[motorD] = -1*joystick.joy1_y1;
    motor[motorE] = -1*joystick.joy1_y1;
    motor[motorF] = joystick.joy1_y2;
    motor[motorG] = joystick.joy1_y2;

  }
}
