/*
 * d_motor.h
 *
 *  Created on: Nov 4, 2023
 *      Author: sssho
 */

#ifndef INC_DEVICE_D_MOTOR_H_
#define INC_DEVICE_D_MOTOR_H_

#include<stdint.h>

#define LEFT_MOTOR	0xf0
#define RIGHT_MOTOR	0x0f
#define DUTY_MAX 90
#define DUTY_MIN 1

enum{
	FORWARD = 0,
	BACK
};

void enableMotors(void);
void disableMotors(void);
void brakeLeftMotors(void);
void brakeRightMotors(void);
void brakeMotors(void);
void smoothMotors(void);
void driveRightMotor(uint8_t);
void driveLeftMotor(uint8_t);
void driveMotors(int8_t left_duty,int8_t right_duty);
uint16_t updateMotors(uint8_t);

#endif /* INC_DEVICE_D_MOTOR_H_ */
