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
void lightLeftLED1(bool com){
	if(com != 0)	LL_GPIO_SetOutputPin(IFL_LED1_GPIO_Port, IFL_LED1_Pin);
	else			LL_GPIO_ResetOutputPin(IFL_LED1_GPIO_Port, IFL_LED1_Pin);
}

void lightLeftLED2(bool com){
	if(com)	LL_GPIO_SetOutputPin(IFL_LED2_GPIO_Port, IFL_LED2_Pin);
	else	LL_GPIO_ResetOutputPin(IFL_LED2_GPIO_Port, IFL_LED2_Pin);
}

void lightLeftLED3(bool com){
	if(com)	LL_GPIO_SetOutputPin(IFL_LED3_GPIO_Port, IFL_LED3_Pin);
	else	LL_GPIO_ResetOutputPin(IFL_LED3_GPIO_Port, IFL_LED3_Pin);
}

void lightRightLED1(bool com){
	if(com)	LL_GPIO_SetOutputPin(IFR_LED1_GPIO_Port, IFR_LED1_Pin);
	else	LL_GPIO_ResetOutputPin(IFR_LED1_GPIO_Port, IFR_LED1_Pin);
}

void lightRightLED2(bool com){
	if(com)	LL_GPIO_SetOutputPin(IFR_LED2_GPIO_Port, IFR_LED2_Pin);
	else	LL_GPIO_ResetOutputPin(IFR_LED2_GPIO_Port, IFR_LED2_Pin);
}

void lightRightLED3(bool com){
	if(com)	LL_GPIO_SetOutputPin(IFR_LED3_GPIO_Port, IFR_LED3_Pin);
	else	LL_GPIO_ResetOutputPin(IFR_LED3_GPIO_Port, IFR_LED3_Pin);
}

/**
* @brief LEDの点灯状態を一括して制御する関数群、正式運用時は一括のみを使う予定
* @param 各LEDのON・OFF、上位4bit -> 左LED群、下位4bit ->　右LED群
*/
void lightLeftLEDs(uint8_t command){
	uint8_t masked_commnad = (command & 0xf0) >> 4;
	lightLeftLED1((masked_commnad&0x01));
	lightLeftLED2((masked_commnad&0x02)>>1);
	lightLeftLED3((masked_commnad&0x04)>>2);
}
void lightRightLEDs(uint8_t command){
	uint8_t masked_commnad = (command & 0x0f);
	lightRightLED1((masked_commnad&0x01));
	lightRightLED2((masked_commnad&0x02)>>1);
	lightRightLED3((masked_commnad&0x04)>>2);
}
void lightIndicators(uint8_t command){
	lightLeftLEDs(command&0xf0);
	lightRightLEDs(command&0x0f);
}
