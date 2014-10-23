#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  none)
#pragma config(Motor,  mtr_S1_C1_1,     left_M2,       tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     left_M3,       tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     right_M3,      tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     left_M1,       tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     right_M1,      tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     right_M2,      tmotorNormal, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include <JoystickDriver.c>

void dt_set(int leftVal, int rightVal); // Function prototype section

task main() {
  SensorMode[S4] = modeRaw;
  int deadband = 456;

  while(1 == 1) {

   getJoystickSettings(joystick);
   dt_set(joystick.joy1_y1, -joystick.joy1_y2);

  }
}

void dt_set(int leftVal, int rightVal) {

    motor[left_M1] = -leftVal;
    motor[left_M2] = leftVal;
    motor[left_M3] = -leftVal;

    motor[right_M1] = -rightVal;
    motor[right_M2] = rightVal;
    motor[right_M3] = -rightVal;

  }
