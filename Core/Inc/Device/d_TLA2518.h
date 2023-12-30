/*
 * d_TLA2518.h
 *
 *  Created on: Oct 25, 2023
 *      Author: sssho
 */

#ifndef INC_DEVICE_D_TLA2518_H_
#define INC_DEVICE_D_TLA2518_H_


#include <stdint.h>
	/*TLA-2518用のマクロ*/
#define		SYSTEM_CONFIG_ADDR 		0x00
#define		GENERAL_CFG_ADDR 		0x01
#define		DATA_CFG_ADDR 			0x02
#define		OSR_CFG_ADDR			0x03
#define		OPMODE_CFG_ADDR			0x04
#define		PIN_CFG_ADDR			0x05
#define		GPIO_CFG_ADDR			0x07
#define		GPO_DRIVE_CFG_ADDR		0x09
#define		GPO_VALUE_ADDR			0x0b
#define		GPI_VALUE_ADDR			0x0d
#define		SEQUENCE_CFG_ADDR		0x10
#define		CHANNEL_SEL_ADDR		0x11
#define		AUTO_SEQ_CH_SEL_ADDR 	0x12

#define		SYSTEM_CONFIG_VALUE 	0x81		// デフォルト、あまり変えることを想定していない
#define		GENERAL_CFG_VALUE 		0x00		// 一括設定
#define		DATA_CFG_VALUE 			0x12		// 通信・波形の設定
#define		OSR_CFG_VALUE			0x00		// 移動平均フィルタのサンプル数
#define		OPMODE_CFG_VALUE		0x00		// 内部のサンプリングレートなど、要調整項目
#define		PIN_CFG_VALUE			0x32		// 各PIOのAD or GPIO設定
#define		GPIO_CFG_VALUE			0x32		// GPIOピンのIO設定
#define		GPO_DRIVE_CFG_VALUE		0x32		// GPOのプルアップ設定
#define		GPO_VALUE_VALUE			0x00		// GPOの出力状態
#define		GPI_VALUE_VALUE			0x00		// GPIの入力状態
#define		SEQUENCE_CFG_VALUE		0x00		// 動作モード設定、0x00 -> manual, 0x01 -> Auto Sequence
#define		CHANNEL_SEL_VALUE		0x00		// manual時のピン指定、0-3bitで1つのみ指定 ch0-7
#define		AUTO_SEQ_CH_SEL_VALUE 	0x00		// Auto Sequence時のCH設定, 必要なら0xcd

/*============================================================
		関数プロトタイプ宣言
============================================================*/
void dtla_initTLA2518();

//  ********　以下の関数は工事中 ********
uint16_t dtla_getAdcCH0();
uint16_t dtla_getAdcCH1();
uint16_t dtla_getAdcCH2();
uint16_t dtla_getAdcCH3();
uint16_t dtla_getAdcCH4();
uint16_t dtla_getAdcCH5();
uint16_t dtla_getAdcCH6();
uint16_t dtla_getAdcCH7();

#endif /* INC_DEVICE_D_TLA2518_H_ */
