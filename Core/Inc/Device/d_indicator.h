/*
 * d_indicator.h
 *
 *  Created on: Nov 4, 2023
 *      Author: sssho
 */

#ifndef INC_DEVICE_D_INDICATOR_H_
#define INC_DEVICE_D_INDICATOR_H_

#include<stdint.h>
#include<stdbool.h>

enum{
	LED_OFF=0,
	LED_ON
};
// 表示用LEDの制御変更
void di_lightRightLED1(bool);
void di_lightRightLED2(bool);
void di_lightRightLED3(bool);
void di_lightLeftLED1(bool);
void di_lightLeftLED2(bool);
void di_lightLeftLED3(bool);

void di_lightSensorFL(bool);
void di_lightSensorL(bool);
void di_lightSensorR(bool);
void di_lightSensorFR(bool);

// 表示用一括変更用のLED制御関数
void di_lightRightLEDs(uint8_t command);
void di_lightLeftLEDs(uint8_t command);
void di_lightIndicators(uint8_t command);
void di_lightSensorLEDs(bool,bool,bool,bool);
#endif /* INC_DEVICE_D_INDICATOR_H_ */
