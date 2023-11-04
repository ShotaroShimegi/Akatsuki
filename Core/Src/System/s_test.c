/*
 * s_test.c
 *
 *  Created on: Nov 4, 2023
 *      Author: sssho
 */

#include<stdio.h>

#include"System/s_test.h"

#include"Device/d_encoder.h"

void testEncoder(void){
	uint32_t total_pulse_l,total_pulse_r,pulse_r,pulse_l;
	while(1){
	  updateEncoders();
	  pulse_l = getEncoderData(LEFT_PULSE);
	  pulse_r = getEncoderData(RIGHT_PULSE);
	  total_pulse_l = getEncoderData(LEFT_SIGMA_PULSE);
	  total_pulse_r = getEncoderData(RIGHT_SIGMA_PULSE);
	  printf("L: %5d, R: %5d\n",pulse_l,pulse_r);
	  printf("totalL: %5d, totalR: %5d\n",total_pulse_l,total_pulse_r);
	  LL_mDelay(1000);
	}
}
