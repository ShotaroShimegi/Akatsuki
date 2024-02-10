/*
 * u_wall_sensor.h
 *
 *  Created on: Feb 3, 2024
 *      Author: sssho
 */

#ifndef INC_UNIT_U_WALL_SENSOR_H_
#define INC_UNIT_U_WALL_SENSOR_H_

#include<stdint.h>
#include"Device/d_TLA2518.h"

enum{
	ARRAY_ID_FR = 0,
	ARRAY_ID_R,
	ARRAY_ID_L,
	ARRAY_ID_FL
};

void uws_initWallSensor();
void uws_updateWallSensor();
void uws_containSensorValue(tla2518_t*);

#endif /* INC_UNIT_U_WALL_SENSOR_H_ */
