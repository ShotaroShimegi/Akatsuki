/*
 * d_MPU6500.h
 *
 *  Created on: Oct 25, 2023
 *      Author: sssho
 */

#ifndef INC_DEVICE_D_MPU6500_H_
#define INC_DEVICE_D_MPU6500_H_

#include <stdint.h>
	/*MPU-6500用のマクロ*/
#define GYRO_FIX 16.4f
#define ACCEL_FIX 2048.0f

#define		WHO_AM_I 				0x75
#define		GYRO_CORREST_REACTION 	0x70
#define		PWR_MGMT_1 				0x6b
#define		CONFIG					0x1a
#define 	GYRO_CONFIG 			0x1b
#define 	GYRO_ZOUT_H 			0x47
#define 	GYRO_ZOUT_L 			0x48

#define		ACCEL_CONFIG 			0x1c
#define		ACCEL_XOUT_H 			0x3b
#define		ACCEL_XOUT_L 			0x3c

/*============================================================
		関数プロトタイプ宣言
============================================================*/
void dmpu_initIMU();
float dmpu_readGyroOmegaZ(void);
float dmpu_readGyroAccelX(void);

#endif /* INC_DEVICE_D_MPU6500_H_ */
