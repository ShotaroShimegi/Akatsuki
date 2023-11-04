/*
 * s_callback.c
 *
 *  Created on: Nov 4, 2023
 *      Author: sssho
 */
#include <stdio.h>

#include"System/s_test.h"

#include"Device/d_MPU6500.h"
#include"Device/d_TLA2518.h"
#include"Device/d_encoder.h"
#include"Device/d_indicator.h"
#include"Device/d_basic_timer.h"

uint16_t timer_cnt = 0;

void doInitializeTask(void){
	printf("Akatsuki System Open\n");
	initIMU();
	initTLA2518();
	enableEncoder();

	basicTimerStart();
}

void doloopTask(void){
	while(1){
		printf("From loop Task,cnt is %5d\n",timer_cnt);
		lightIndicators(0xf0);
		waitMs(500);
		lightIndicators(0x00);
		waitMs(500);
	}
}

void doCallbackTask(void){
	timer_cnt++;
}

