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
void lightRightLED1(bool);
void lightRightLED2(bool);
void lightRightLED3(bool);
void lightLeftLED1(bool);
void lightLeftLED2(bool);
void lightLeftLED3(bool);

// 表示用一括変更用のLED制御関数
void lightRightLEDs(uint8_t command);
void lightLeftLEDs(uint8_t command);
void lightIndicators(uint8_t command);


#endif /* INC_DEVICE_D_INDICATOR_H_ */
