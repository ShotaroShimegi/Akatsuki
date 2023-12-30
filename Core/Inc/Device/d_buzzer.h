/*
 * d_buzzer.h
 *
 *  Created on: Nov 2, 2023
 *      Author: sssho
 */

#ifndef INC_DEVICE_D_BUZZER_H_
#define INC_DEVICE_D_BUZZER_H_

#include"stdint.h"

void dbz_enableMelody(void);
void dbz_disableMelody(void);
void dbz_Melody(uint16_t,uint16_t);

#endif /* INC_HARDWARE_BUZZER_H_ */

