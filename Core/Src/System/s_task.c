/*
 * s_callback.c
 *
 *  Created on: Nov 4, 2023
 *      Author: sssho
 */
#include <stdio.h>

#include "System/s_test.h"
#include "System/s_task.h"
#include "System/s_mode.h"

#include "Unit/u_music.h"
#include "Unit/u_dial.h"
#include "Unit/u_wall_sensor.h"

#include "Device/d_MPU6500.h"
#include "Device/d_TLA2518.h"
#include "Device/d_encoder.h"
#include "Device/d_indicator.h"
#include "Device/d_basic_timer.h"
#include "Device/d_motor.h"
#include "Device/d_buzzer.h"

#include"main.h"

uint32_t count1,count2,count_a,count_tim5;

/**
* @brief main loop 	前に1度だけ行う処理
*/
void doInitializeTask(void){
	printf("Akatsuki System Open\n");
	// Deviceレイヤの初期化、ユニットに組み込んだら捨ててよい
	dbz_enableMelody();
	di_lightIndicators(0xff);
	dbt_waitMs(500);
	dm_disableMotors();
	dmpu_initIMU();
//	dtla_initTLA2518();
	um_MelodySummer();
	de_enableEncoder();

	// Device Unitの初期化
	uws_initWallSensor();

//	basicTimerStart();

	// 初期化修了のインターフェース
	di_lightIndicators(0x00);
	dbt_waitMs(500);
}

/**
* @brief main loop中の処理
*/
void doloopTask(void){
	printf("Loop Task In\n");
	while(1){
		selectMainMode();
		printf("Loop Task Out\n");
	}
}

/**
* @brief 1kHz タイマ割込みのタスク
*/
void doCallbackTask(void){
	uws_updateWallSensor();		// 壁センサの更新
								// 測定絡みの更新
}

/**
* @brief 左モータDutyHIGH周期 callbackで行う処理
*/
void doMotorLeftCallbackTask(void){
	dm_brakeLeftMotors();
}

/**
* @brief 右モータDutyHIGH周期 callbackで行う処理
*/
void doMotorRightCallbackTask(void){
	dm_brakeRightMotors();
}

/**
* @brief 両方モータ
*/
void doMotorBothCallbackTask(void){
	LL_TIM_OC_SetCompareCH1(TIM5, dm_updateMotors(0xf0));
	LL_TIM_OC_SetCompareCH2(TIM5, dm_updateMotors(0x0f));

//	LL_TIM_SetAutoReload(TIM5,200-1);
//	LL_TIM_SetCounter(TIM5, 0);
}

