/*
 * d_encoder.h
 *
 *  Created on: Oct 28, 2023
 *      Author: sssho
 */

#ifndef INC_DEVICE_D_ENCODER_H_
#define INC_DEVICE_D_ENCODER_H_

#include<stdint.h>

enum{
	LEFT_PULSE
	,LEFT_SIGMA_PULSE
	,RIGHT_PULSE
	,RIGHT_SIGMA_PULSE
};

void enableEncoder(void);
void disableEncoder(void);
void updateEncoders(void);
void resetEncoders(void);
int32_t getEncoderData(uint8_t command);

#endif /* INC_DEVICE_D_ENCODER_H_ */
