/*
 * s_test.c
 *
 *  Created on: Nov 4, 2023
 *      Author: sssho
 */

#include<stdio.h>

#include"System/s_test.h"

#include"Unit/u_wall_sensor.h"

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
* @brief バッテリーチェッカー(TLA2718の動作確認)
*/
void testBattery(void){
	uint16_t battery_adc = 0;
	while(1){
		battery_adc = dtla_getAdcCH(0x00).value;
		printf("Check Battery is %d\n",battery_adc);
		dbt_waitMs(500);
	}
}

/**
* @brief 壁センサの動作確認モード
*/
void testWallSensor(void){
	tla2518_t sensor[4];
	dbt_basicTimerStart();

	while(1){
		uws_containSensorValue(sensor);
		printf("FL(ID: %2x): %4d, L(ID: %2d): %4d, R(ID: %2d):%4d, FR(ID: %2d): %4d\n",
				sensor[ARRAY_ID_FL].id,sensor[ARRAY_ID_FL].value,
				sensor[ARRAY_ID_L].id,sensor[ARRAY_ID_L].value,
				sensor[ARRAY_ID_R].id,sensor[ARRAY_ID_R].value,
				sensor[ARRAY_ID_FR].id,sensor[ARRAY_ID_FR].value);
		di_lightIndicators(0xf0);
		dbt_waitMs(500);
		di_lightIndicators(0x0f);
		dbt_waitMs(500);
	}

}
