/*
 * d_TLA2518.c
 *
 *  Created on: Oct 25, 2023
 *      Author: sssho
 */
#include"Device/d_TLA2518.h"
#include<stdio.h>

#include"main.h"
#include"spi.h"

/**
* @brief
* @param1 SPIのペリフェラル
* @param2 送信データ配列
* @param3 受信データ配列
* @param4 配列サイズ
* @details　SPIペリフェラルを使うための何か
*/
void tlaSPIControl(SPI_TypeDef *SPIx, uint8_t *tx_data, uint8_t *rx_data,uint8_t length) {
	uint8_t count = length;

	if(LL_SPI_IsActiveFlag_RXNE(SPIx) == SET)		LL_SPI_ReceiveData8(SPIx);
	if(LL_SPI_IsEnabled(SPIx) == RESET ) 			LL_SPI_Enable(SPIx);

	LL_GPIO_SetOutputPin(GYRO_CS_GPIO_Port, GYRO_CS_Pin);
	LL_GPIO_ResetOutputPin(ADC_CS_GPIO_Port, ADC_CS_Pin);

	while(count > 0){
		LL_SPI_TransmitData8(SPIx, *tx_data++);
		while( LL_SPI_IsActiveFlag_TXE(SPIx) == RESET );
		while( LL_SPI_IsActiveFlag_RXNE(SPIx) == RESET );
		*rx_data++ = LL_SPI_ReceiveData8(SPIx);
		count--;
	}
	LL_GPIO_SetOutputPin(ADC_CS_GPIO_Port, ADC_CS_Pin);
}

/**
* @brief
* @param1 SPIのペリフェラル
* @param2 送信データ配列
* @param3 受信データ配列
* @param4 配列サイズ
* @details　SPIペリフェラルを使うための何か
*/
void tlaSPIRead(SPI_TypeDef *SPIx,uint8_t *tx_data, uint8_t *rx_data,uint8_t length) {
	uint8_t count = length;

	if(LL_SPI_IsActiveFlag_RXNE(SPIx) == SET)		LL_SPI_ReceiveData8(SPIx);
	if(LL_SPI_IsEnabled(SPIx) == RESET ) 			LL_SPI_Enable(SPIx);

	LL_GPIO_SetOutputPin(GYRO_CS_GPIO_Port, GYRO_CS_Pin);
	LL_GPIO_ResetOutputPin(ADC_CS_GPIO_Port, ADC_CS_Pin);

	while(count > 0){
		LL_SPI_TransmitData8(SPIx, *tx_data++);
		while( LL_SPI_IsActiveFlag_TXE(SPIx) == RESET );
		while(LL_SPI_IsActiveFlag_RXNE(SPIx) == RESET );
		*rx_data++ = LL_SPI_ReceiveData8(SPIx);
		count--;
	}
	LL_GPIO_SetOutputPin(ADC_CS_GPIO_Port, ADC_CS_Pin);
}

//+++++++++++++++++++++++++++++++++++++++++++++++
// tlaReadByte
//	@brief  のデータをリクエスト・受信する
// @param addres ほしいデータのアドレス（IMU側データシートを参照）
// @return 抽出したデータ
//+++++++++++++++++++++++++++++++++++++++++++++++
uint8_t tlaReadByte(uint8_t addres) {
	uint8_t trans_data[3];
	uint8_t receive_data[3];

	trans_data[0] = 0x10;				// readコマンド
	trans_data[1] = addres;
	trans_data[2] = 0x00;

	tlaSPIControl(SPI1, trans_data, receive_data, 3);
	trans_data[0] = 0x00;				// 受信専用のダミー
	trans_data[1] = 0x00;
	trans_data[2] = 0x00;
	tlaSPIRead(SPI1, trans_data,receive_data, 3);
	return receive_data[0];
}

//+++++++++++++++++++++++++++++++++++++++++++++++
// write_byte
//	@brief IMUにデータを送信する
// @param addres 書き込みたいデータのアドレス（IMU側データシートを参照）
// @param addres 書き込みたいデータの内容（IMU側データシートを参照）
//+++++++++++++++++++++++++++++++++++++++++++++++
void tlaWriteByte(uint8_t addres,uint8_t data) {
	uint8_t trans_data[3];
	uint8_t receive_data[3];

	trans_data[0] = 0x08;				//書込みコマンド
	trans_data[1] = addres;
	trans_data[2] = data;

	tlaSPIControl(SPI1, trans_data, receive_data, 3);
}

//+++++++++++++++++++++++++++++++++++++++++++++++
// tlaReadDataFormat
// @brief 手動モードでピン指定された後に呼び出される想定
// @param addres ほしいデータのアドレス（IMU側データシートを参照）
// @return 12bitに変換したADC後のデータ
//+++++++++++++++++++++++++++++++++++++++++++++++
uint16_t tlaReadDataFormat(uint8_t* id) {
	uint8_t trans_data[3];
	uint8_t receive_data[3];
	uint16_t value = 0;

	trans_data[0] = 0x00;				// ADCフェイズ用の待機と受信用の変換
	trans_data[1] = 0x00;
	trans_data[2] = 0x00;

	tlaSPIControl(SPI1, trans_data, receive_data, 3);
	tlaSPIRead(SPI1, trans_data, receive_data, 3);

	value = ((uint16_t)receive_data[0]) << 4 | ((receive_data[1] & 0x40) >> 4);
	*id = receive_data[1] & 0x04;
	return value;
}

//+++++++++++++++++++++++++++++++++++++++++++++++
// initIMU
//	@brief IMUにデータを送信する
// @param addres 書き込みたいデータのアドレス（IMU側データシートを参照）
// @param addres 書き込みたいデータの内容（IMU側データシートを参照）
//+++++++++++++++++++++++++++++++++++++++++++++++
void dtla_initTLA2518(void){
	LL_SPI_Enable(SPI1);

	uint8_t default_value = tlaReadByte(SYSTEM_CONFIG_ADDR);
//	printf("ADC_Status ? -> 0x%x\n", default_value);
//
//	if(default_value != SYSTEM_CONFIG_VALUE){
//		while(default_value != SYSTEM_CONFIG_VALUE){
//			printf("ADC Error:ADC Status? -> 0x%x\n", default_value);
//			default_value = tlaReadByte(SYSTEM_CONFIG_ADDR);
//			LL_mDelay(1000);
//		}
//	}
//	printf("ADC OK\n");

	tlaWriteByte(GENERAL_CFG_ADDR,GENERAL_CFG_VALUE),		LL_mDelay(10);
	tlaWriteByte(DATA_CFG_ADDR,DATA_CFG_VALUE),				LL_mDelay(10);
	tlaWriteByte(OSR_CFG_ADDR,OSR_CFG_VALUE),				LL_mDelay(10);
	tlaWriteByte(OPMODE_CFG_ADDR,OPMODE_CFG_VALUE),			LL_mDelay(10);

	tlaWriteByte(PIN_CFG_ADDR,PIN_CFG_VALUE),				LL_mDelay(10);
	tlaWriteByte(GPO_DRIVE_CFG_ADDR,GPO_DRIVE_CFG_VALUE),	LL_mDelay(10);
	tlaWriteByte(SEQUENCE_CFG_ADDR,SEQUENCE_CFG_VALUE),		LL_mDelay(10);

	printf("ADC_Status ? -> 0x%x\n", default_value);
	if(default_value != SYSTEM_CONFIG_VALUE){
		while(default_value != SYSTEM_CONFIG_VALUE){
			printf("ADC Error:ADC Status? -> 0x%x\n", default_value);
			default_value = tlaReadByte(SYSTEM_CONFIG_ADDR);
			LL_mDelay(1000);
		}
	}
	printf("ADC OK\n");
}

//+++++++++++++++++++++++++++++++++++++++++++++++
// dtla_getAdcCH
//	@brief 特定のチャンネルからデータを抜き取る
//+++++++++++++++++++++++++++++++++++++++++++++++
uint16_t dtla_getAdcCH0(){
	uint16_t value = 0;
	uint8_t id = 9;
	// まずは手動モードなので、チャンネル設定を書き込む
	tlaWriteByte(CHANNEL_SEL_ADDR, 0x00);
	// 読込を行うけど、レジスター読込とは少し異なるっぽい
	value = tlaReadDataFormat(&id);
	printf("Value is %4d, ID is %d, ",value,id);
	return 0;
}

uint16_t dtla_getAdcCH1();
uint16_t dtla_getAdcCH2();
uint16_t dtla_getAdcCH3();
uint16_t dtla_getAdcCH4();
uint16_t dtla_getAdcCH5();
uint16_t dtla_getAdcCH6();
uint16_t dtla_getAdcCH7();
