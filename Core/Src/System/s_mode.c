/*
 * s_mode.c
 *
 *  Created on: Dec 10, 2023
 *      Author: sssho
 */
#include<stdint.h>
#include<stdio.h>

#include"System/s_mode.h"
#include"System/s_test.h"

#include"Unit/u_dial.h"

#include"Device/d_indicator.h"
#include"Device/d_basic_timer.h"

/**
* @brief　	モードはメインメニューから各項目が選べる形式。とりあえず再左は使わない方針にしたい
* 			メインでどのモード選択かをまず選ぶ
*/
void selectMainMode(){
	uint8_t mode = 0;
	// ダイアルを起動する
	ud_startDial();
	// モード選択を実行する
	mode = ud_selectDial(1);
	// ダイアルをオフにする
	ud_stopDial();

	di_lightLeftLEDs(0xf0),dbt_waitMs(500);
	di_lightLeftLEDs(0x00),dbt_waitMs(500);
	di_lightLeftLEDs(0xf0),dbt_waitMs(500);
	di_lightLeftLEDs(0x00),dbt_waitMs(500);

	switch(mode){
		case 0:
			printf("Mode: No-mode \n");
			break;
		case 1:
			printf("Mode: No-mode Search\n");
			break;
		case 2:
			printf("Mode: No-mode Fast Run\n");
			break;
		case 3:
			printf("Mode: Battery Test Mode\n");
			selectTestMode();
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		default:	// 基本は存在しないはず
			break;
	}
}

void selectSearchMode(){

}

void selectRunMode(){

}

void selectTestMode(){
	uint8_t mode = 0;
	di_lightLeftLEDs(0xf0);
	// ダイアルを起動する
	ud_startDial();
	// モード選択を実行する
	mode = ud_selectDial(1);
	// ダイアルをオフにする
	ud_stopDial();

	di_lightLeftLEDs(0xf0),dbt_waitMs(500);
	di_lightLeftLEDs(0x00),dbt_waitMs(500);
	di_lightLeftLEDs(0xf0),dbt_waitMs(500);
	di_lightLeftLEDs(0x00),dbt_waitMs(500);

	switch(mode){
		case 0:
			printf("TestMode: No-mode\n");
			break;
		case 1:
			printf("TestMode: Wall Sensor Test\n");
			testWallSensor();
			break;
		case 2:
			printf("TestMode: No-mode\n");
			break;
		case 3:
			printf("TestMode: Battery Test\n");
			testBattery();
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		default:	// 基本は存在しないはず
			break;
	}
}

void selectLogMode(){

}
