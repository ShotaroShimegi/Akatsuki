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

void dm_enableMotors(void);
void dm_disableMotors(void);
void dm_brakeLeftMotors(void);
void dm_brakeRightMotors(void);
void dm_brakeMotors(void);
void dm_smoothMotors(void);
void dm_driveRightMotor(uint8_t);
void dm_driveLeftMotor(uint8_t);
void dm_driveMotors(int8_t left_duty,int8_t right_duty);
uint16_t dm_updateMotors(uint8_t);

#endif /* INC_DEVICE_D_MOTOR_H_ */
