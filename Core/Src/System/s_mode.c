/*
 * s_mode.c
 *
 *  Created on: Dec 10, 2023
 *      Author: sssho
 */
#include<stdint.h>
#include<stdio.h>

#include"System/s_mode.h"

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
	startDial();
	// モード選択を実行する
	mode = selectDial(1);
	// ダイアルをオフにする
	stopDial();

	lightIndicators(0xff),waitMs(100);
	lightIndicators(0x00),waitMs(100);
	lightIndicators(0xff),waitMs(100);
	lightIndicators(0x00),waitMs(100);

	switch(mode){
		case 0:
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
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

}

void selectLogMode(){

}
