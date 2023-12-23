/*
 * u_dial.h
 *
 *  Created on: Nov 4, 2023
 *      Author: sssho
 */

#ifndef INC_UNIT_U_DIAL_H_
#define INC_UNIT_U_DIAL_H_

#include<stdint.h>

typedef struct {
	uint8_t mode;
	uint16_t row_value;
	float ratio;
}t_dial;

void startDial();
void stopDial();
t_dial convertDialStruct(uint16_t cnt);
uint8_t selectDial(uint8_t phase);

#endif /* INC_UNIT_U_DIAL_H_ */
