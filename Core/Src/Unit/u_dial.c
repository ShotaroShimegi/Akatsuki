/*
 * u_dial.c
 *
 *  Created on: Nov 4, 2023
 *      Author: sssho
 */
#include<stdio.h>

#include"Unit/u_dial.h"

#include"Device/d_encoder.h"
#include"Device/d_indicator.h"

const int MAX_MODE_NUM = 8;
t_dial right,left;

void ud_startDial(){
	// ダイアル使う前の変数初期化
	right.mode = 0;
	right.ratio = 0.0;
	right.row_value = 0;
	left.mode = 0;
	left.ratio = 0.0f;
	left.row_value = 0;

	// エンコーダの有効化
	de_enableEncoder();
}

void ud_stopDial(){
	// ダイアル使った後の後処理
	right.mode = 0;
	right.ratio = 0.0;
	right.row_value = 0;
	left.mode = 0;
	left.ratio = 0.0f;
	left.row_value = 0;

	// エンコーダ無効化
	de_disableEncoder();
}

/**
* @brief　	t_dail型をTIMの生値から保存する関数
* @return   t_dial型を返すので引数で格納して欲しい
*/
t_dial ud_convertDialStruct(uint16_t cnt){
	t_dial temp;
	temp.row_value = cnt;
	temp.ratio = (float)temp.row_value / 65536;
	temp.mode = temp.ratio * MAX_MODE_NUM;
	return temp;
}

/**
* @brief　	do_whileでこれだけ呼ばれる前提で実装を進める
* @return   戻り値は欲しいモードについて
*/
uint8_t ud_selectDial(uint8_t phase){
	static uint8_t pre_mode;
	uint16_t temp_count_r,temp_count_l;
	de_resetEncoders();
	left.mode = 0;
	right.mode = 0;
	// モードを返すようにする？
	do {
		// まずはエンコーダ処理
		de_updateEncoders();
		temp_count_l = de_getEncoderData(LEFT_SIGMA_PULSE);
		temp_count_r = de_getEncoderData(RIGHT_SIGMA_PULSE);
		left = ud_convertDialStruct(temp_count_l);
		right = ud_convertDialStruct(temp_count_r);
		// 前との変更次第で表示を変える
		if((right.mode - pre_mode) != 0){
			printf("Mode:%2d \n",right.mode);
			di_lightRightLEDs(right.mode & 0x07);
		}
		pre_mode = right.mode;
	}while(left.mode != 2);
	// 確定した右のモードを返す
	printf("Enter Mode:%2d \n",right.mode);
	return right.mode;
}
