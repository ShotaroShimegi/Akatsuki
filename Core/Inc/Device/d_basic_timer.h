/*
 * d_basic_timer.h
 *
 *  Created on: Nov 2, 2023
 *      Author: sssho
 */

#ifndef INC_DEVICE_D_BASIC_TIMER_H_
#define INC_DEVICE_D_BASIC_TIMER_H_

#include "stdint.h"
#include "stm32f4xx_ll_utils.h"

void basicTimerCallback(void);
void basicTimerStart(void);
void basicTimerPause(void);
void waitMs(uint16_t ms);
void waitUs(uint16_t us);


#endif /* INC_DEVICE_D_BASIC_TIMER_H_ */
