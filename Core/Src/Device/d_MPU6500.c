/*
 * d_MPU6500.h
 *
 *  Created on: Oct 25, 2023
 *      Author: sssho
 */
#include"Device/d_MPU6500.h"

#include"main.h"
#include"spi.h"

#include<stdio.h>

/**
* @brief
* @param argument1
* @param (As many as the number of arguments)
* @return
* (@sa Functions to should refer to)
* @details
*/

void SPI_Control(SPI_TypeDef *SPIx, uint8_t *tx_data, uint8_t *rx_data,uint8_t length) {
	uint8_t count = length;

	LL_GPIO_SetOutputPin(ADC_CS_GPIO_Port, ADC_CS_Pin);
	LL_GPIO_ResetOutputPin(GYRO_CS_GPIO_Port, GYRO_CS_Pin);

	if(LL_SPI_IsActiveFlag_RXNE(SPIx) == SET)	LL_SPI_ReceiveData8(SPIx);
	if(LL_SPI_IsEnabled(SPIx) == RESET ) 			LL_SPI_Enable(SPIx);

	  while(count > 0){
	    LL_SPI_TransmitData8(SPIx, *tx_data++);
	    while( LL_SPI_IsActiveFlag_TXE(SPIx) == RESET );
	    while( LL_SPI_IsActiveFlag_RXNE(SPIx) == RESET );
	    *rx_data++ = LL_SPI_ReceiveData8(SPIx);
	    count--;
	  }
	LL_GPIO_SetOutputPin(GYRO_CS_GPIO_Port, GYRO_CS_Pin);
}

//+++++++++++++++++++++++++++++++++++++++++++++++
// readByte
//	@brief  IMUのデータをリクエスト・受信する
// @param addres ほしいデータのアドレス（IMU側データシートを参照）
// @return 抽出したデータ
//+++++++++++++++++++++++++++++++++++++++++++++++
uint8_t readByte(uint8_t addres)
{
	uint8_t trans_data[2];
	uint8_t receive_data[2];

	trans_data[0] = addres | 0x80;
	trans_data[1] = 0x00;

	SPI_Control(SPI1, trans_data, receive_data, 2);

	return receive_data[1];
}

//+++++++++++++++++++++++++++++++++++++++++++++++
// write_byte
//	@brief IMUにデータを送信する
// @param addres 書き込みたいデータのアドレス（IMU側データシートを参照）
// @param addres 書き込みたいデータの内容（IMU側データシートを参照）
//+++++++++++++++++++++++++++++++++++++++++++++++
void writeByte(uint8_t addres,uint8_t data)
{
	uint8_t trans_data[2];
	uint8_t receive_data[2];

	trans_data[0] = addres & 0x7f;
	trans_data[1] = data;

	SPI_Control(SPI1, trans_data, receive_data, 2);
}
//+++++++++++++++++++++++++++++++++++++++++++++++
// initIMU
//	@brief IMUにデータを送信する
// @param addres 書き込みたいデータのアドレス（IMU側データシートを参照）
// @param addres 書き込みたいデータの内容（IMU側データシートを参照）
//+++++++++++++++++++++++++++++++++++++++++++++++

void initIMU(void) {
	LL_SPI_Enable(SPI1);

	uint8_t who_am_i = readByte(WHO_AM_I);

	if(who_am_i != GYRO_CORREST_REACTION){
		while(who_am_i != GYRO_CORREST_REACTION){
			printf("Gyro Error: Who am I ? -> 0x%x\n", who_am_i);
			who_am_i = readByte(WHO_AM_I);
			LL_mDelay(100);
		}
	}
	printf("Who am I ? -> 0x%x\n", who_am_i);
	printf("Gyro OK\n");

	writeByte(PWR_MGMT_1,0x00);
	LL_mDelay(10);
	writeByte(CONFIG,0x00);
	LL_mDelay(10);
	writeByte(GYRO_CONFIG,0x18);
	LL_mDelay(10);
	writeByte(ACCEL_CONFIG,0x18);
	LL_mDelay(10);
}

float readGyroOmegaZ(void){
	int16_t omega_raw_z;
	float real_omega;
	omega_raw_z = (int16_t)(readByte(GYRO_ZOUT_H) << 8 | readByte(GYRO_ZOUT_L));	//0x47が上位，0x48が下位の16bitデータでジャイロ値を取得
	real_omega = (float)(omega_raw_z / GYRO_FIX);
	return real_omega;
}

float readGyroAccelX(void){
	int16_t accel_raw_x;
	float real_accel;
	accel_raw_x = (int16_t)(readByte(ACCEL_XOUT_H) << 8 | readByte(ACCEL_XOUT_L));	//0x47が上位，0x48が下位の16bitデータでジャイロ値を取得
	real_accel = (float)(accel_raw_x / ACCEL_FIX);
	return real_accel;
}
