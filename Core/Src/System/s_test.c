/*
 * s_test.c
 *
 *  Created on: Nov 4, 2023
 *      Author: sssho
 */

#include<stdio.h>

#include"System/s_test.h"

#include"Device/d_encoder.h"
#include"Device/d_basic_timer.h"
#include"Device/d_motor.h"
#include"Device/d_TLA2518.h"
#include"Device/d_indicator.h"

/**
* @brief エンコーダの動作確認
*/
void testEncoder(void){
	uint32_t total_pulse_l,total_pulse_r,pulse_r,pulse_l;
	while(1){
	  de_updateEncoders();
	  pulse_l = de_getEncoderData(LEFT_PULSE);
	  pulse_r = de_getEncoderData(RIGHT_PULSE);
	  total_pulse_l = de_getEncoderData(LEFT_SIGMA_PULSE);
	  total_pulse_r = de_getEncoderData(RIGHT_SIGMA_PULSE);
	  printf("L: %5d, R: %5d\n",pulse_l,pulse_r);
	  printf("totalL: %5d, totalR: %5d\n",total_pulse_l,total_pulse_r);
	  dbt_waitMs(1000);
	}
}

/**
* @brief モータの動作確認, 少しずつDutyは上がるはず
*/

extern uint8_t duty_left_abs;
extern uint8_t duty_right_abs;
extern int8_t motor_left_dir;
extern int8_t motor_right_dir;

void testMotor(void){
	// 以下の内容はモータテスト用
	dm_enableMotors();
	// 1秒ごとにDuty上げてみようか
	for(uint8_t i=0;i<7;i++){
		di_lightIndicators(i);
//			driveMotors(i*5, i*5);
		printf("Report: duty_L-R: %10d, %10d\n"
				,duty_left_abs,duty_right_abs);
		printf("Report: dir_L-R: %10d, %10d\n"
							,motor_left_dir,motor_right_dir);
		dbt_waitMs(1000);
	}
	printf("END\n");
	dm_disableMotors();
	dbt_waitMs(2000);
}

/**
* @brief 壁センサの
*/
void testBattery(void){
	uint16_t battery_adc = 0;
	while(1){
		dtla_getAdcCH(0x00);
		printf("Check Battery is %d\n",battery_adc);
		dbt_waitMs(500);
	}
}
