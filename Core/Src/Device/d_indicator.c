/*
 * d_indicator.c
 *
 *  Created on: Nov 4, 2023
 *      Author: sssho
 */

#include"main.h"
#include<stdio.h>
#include"Device/d_indicator.h"

/**
* @brief 各個別のLEDの点灯状態を制御する関数群、正式運用時は一括のみを使う予定
* @param LEDのON・OFF、false -> OFF, true -> ON
*/
void di_lightLeftLED1(bool com){
	if(com != 0)	LL_GPIO_SetOutputPin(IFL_LED1_GPIO_Port, IFL_LED1_Pin);
	else			LL_GPIO_ResetOutputPin(IFL_LED1_GPIO_Port, IFL_LED1_Pin);
}

void di_lightLeftLED2(bool com){
	if(com)	LL_GPIO_SetOutputPin(IFL_LED2_GPIO_Port, IFL_LED2_Pin);
	else	LL_GPIO_ResetOutputPin(IFL_LED2_GPIO_Port, IFL_LED2_Pin);
}

void di_lightLeftLED3(bool com){
	if(com)	LL_GPIO_SetOutputPin(IFL_LED3_GPIO_Port, IFL_LED3_Pin);
	else	LL_GPIO_ResetOutputPin(IFL_LED3_GPIO_Port, IFL_LED3_Pin);
}

void di_lightRightLED1(bool com){
	if(com)	LL_GPIO_SetOutputPin(IFR_LED1_GPIO_Port, IFR_LED1_Pin);
	else	LL_GPIO_ResetOutputPin(IFR_LED1_GPIO_Port, IFR_LED1_Pin);
}

void di_lightRightLED2(bool com){
	if(com)	LL_GPIO_SetOutputPin(IFR_LED2_GPIO_Port, IFR_LED2_Pin);
	else	LL_GPIO_ResetOutputPin(IFR_LED2_GPIO_Port, IFR_LED2_Pin);
}

void di_lightRightLED3(bool com){
	if(com)	LL_GPIO_SetOutputPin(IFR_LED3_GPIO_Port, IFR_LED3_Pin);
	else	LL_GPIO_ResetOutputPin(IFR_LED3_GPIO_Port, IFR_LED3_Pin);
}

void di_lightSensorFL(bool com){
	if(com)	LL_GPIO_SetOutputPin(SEN_LED_FL_GPIO_Port,SEN_LED_FL_Pin);
	else	LL_GPIO_ResetOutputPin(IFR_LED3_GPIO_Port, IFR_LED3_Pin);
}

void di_lightSensorL(bool com){
	if(com)	LL_GPIO_SetOutputPin(SEN_LED_L_GPIO_Port, SEN_LED_L_Pin);
	else	LL_GPIO_ResetOutputPin(SEN_LED_L_GPIO_Port, SEN_LED_L_Pin);
}

void di_lightSensorR(bool com){
	if(com)	LL_GPIO_SetOutputPin(SEN_LED_R_GPIO_Port, SEN_LED_R_Pin);
	else	LL_GPIO_ResetOutputPin(SEN_LED_R_GPIO_Port, SEN_LED_R_Pin);
}
void di_lightSensorFR(bool com){
	if(com)	LL_GPIO_SetOutputPin(SEN_LED_FR_GPIO_Port, SEN_LED_FR_Pin);
	else	LL_GPIO_ResetOutputPin(SEN_LED_FR_GPIO_Port, SEN_LED_FR_Pin);
}

/**
* @brief LEDの点灯状態を一括して制御する関数群、正式運用時は一括のみを使う予定
* @param 各LEDのON・OFF、上位4bit -> 左LED群、下位4bit ->　右LED群
*/
void di_lightLeftLEDs(uint8_t command){
	uint8_t masked_commnad = (command & 0xf0) >> 4;
	di_lightLeftLED1((masked_commnad&0x01));
	di_lightLeftLED2((masked_commnad&0x02)>>1);
	di_lightLeftLED3((masked_commnad&0x04)>>2);
}
void di_lightRightLEDs(uint8_t command){
	uint8_t masked_commnad = (command & 0x0f);
	di_lightRightLED1((masked_commnad&0x01));
	di_lightRightLED2((masked_commnad&0x02)>>1);
	di_lightRightLED3((masked_commnad&0x04)>>2);
}
void di_lightIndicators(uint8_t command){
	di_lightLeftLEDs(command&0xf0);
	di_lightRightLEDs(command&0x0f);
}
void di_lightSensorLEDs(bool com_fl,bool com_l,bool com_r,bool com_fr){
	di_lightSensorFL(com_fl);
	di_lightSensorL(com_l);
	di_lightSensorR(com_r);
	di_lightSensorFR(com_fr);
}
