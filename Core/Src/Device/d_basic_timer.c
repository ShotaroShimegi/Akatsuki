/*
 * d_basic_timer.c
 *
 *  Created on: Nov 2, 2023
 *      Author: sssho
 */

#include "Device/d_basic_timer.h"
#include "tim.h"

#include "stm32f4xx_ll_tim.h"
#include "stm32f4xx_ll_utils.h"

/**
* @brief タイマ割込みのスタート
*/
void basicTimerStart(void){
	LL_TIM_EnableIT_UPDATE(TIM10);
	LL_TIM_EnableCounter(TIM10);
}

/**
* @brief タイマ割込みの停止
*/
void basicTimerPause(void) {
	LL_TIM_DisableCounter(TIM10);
	LL_TIM_DisableIT_UPDATE(TIM10);
}

/**
* @brief　	特定時間待機する関数
* @param	ms	待機する時間 [msec]
*/
void waitMs(uint16_t ms) {
	LL_mDelay(ms);
}

/**
* @brief　	特定時間待機する関数
* @param	us	待機する時間 [usec]
*/
void waitUs(uint16_t us) {
	if(us > 999)	us = 999;
	volatile uint16_t count = TIM11->CNT + us;
	LL_TIM_EnableCounter(TIM11);
	while(TIM11->CNT < count);
	LL_TIM_DisableCounter(TIM11);
	TIM11->CNT = 0;
}
