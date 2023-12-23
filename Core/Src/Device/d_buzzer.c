/*
 * d_buzzer.c
 *
 *  Created on: Nov 2, 2023
 *      Author: sssho
 */

#include "Device/d_buzzer.h"
#include "Device/d_basic_timer.h"

#include"stm32f4xx_ll_tim.h"

/**
* @brief
* @param argument1
* @param (As many as the number of arguments)
* @return
* (@sa Functions to should refer to)
* @details
*/

void enableMelody(void){
	LL_TIM_CC_DisableChannel(TIM1, LL_TIM_CHANNEL_CH2);
	LL_TIM_CC_EnableChannel(TIM1, LL_TIM_CHANNEL_CH2N);

	LL_TIM_OC_SetIdleState(TIM1, LL_TIM_CHANNEL_CH2N,1);
	LL_TIM_OC_SetIdleState(TIM1, LL_TIM_CHANNEL_CH2,0);

	LL_TIM_SetAutoReload(TIM1,100-1);
	LL_TIM_OC_SetCompareCH2(TIM1, 50-1);
	LL_TIM_SetCounter(TIM1, 0);

	LL_TIM_EnableCounter(TIM1);
	LL_TIM_EnableAllOutputs(TIM1);
}

void disableMelody(void){
	LL_TIM_CC_DisableChannel(TIM1, LL_TIM_CHANNEL_CH2N);
	LL_TIM_DisableCounter(TIM1);
}

void stopMelody(void){
	LL_TIM_OC_SetCompareCH2(TIM1, 1);
}

void Melody(uint16_t hz, uint16_t ms) {
	LL_TIM_SetAutoReload(TIM1,100000/hz);
	LL_TIM_OC_SetCompareCH2(TIM1, 95000 / hz );
	LL_TIM_SetCounter(TIM1, 0);
	LL_mDelay(ms);
	stopMelody();
}
