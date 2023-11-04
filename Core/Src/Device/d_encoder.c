/*
 * d_encoder.c
 *
 *  Created on: Oct 28, 2023
 *      Author: sssho
 */
// エンコーダを使うためのデバイスクラス
#include "tim.h"
#include "Device/d_encoder.h"

int32_t enc_pulse_left;
int32_t enc_pulse_sigma_left;
int32_t enc_pulse_right;
int32_t enc_pulse_sigma_right;

/**
 * enableEncoder
* @brief　エンコーダ機能の有効化
*/
void enableEncoder(void){
	// 使用するTIM関連の初期化
	TIM2->CNT = 0;
	TIM3->CNT = 0;
	LL_TIM_EnableCounter(TIM2);
	LL_TIM_EnableCounter(TIM3);

	// 変数の初期化
	enc_pulse_left = 0;
	enc_pulse_sigma_left = 0;
	enc_pulse_right = 0;
	enc_pulse_sigma_right = 0;
}

/* disableEncoder
* @brief　エンコーダ機能の有効化
*/
void disableEncoder(void){
	LL_TIM_DisableCounter(TIM2);
	LL_TIM_DisableCounter(TIM3);
}

/* resetEncoders
* @brief　エンコーダ機能の有効化
*/
void resetEncoders(void){
	enc_pulse_sigma_left = 0;
	enc_pulse_sigma_right = 0;
}

/**
 * getEncoderData
* @brief エンコーダ関連の値を更新する、更新周期依存は関数の呼び出しタイミングに依存
* @param *TIMx 取得したいエンコーダタイマ、左:TIM3,  右: TIM2
*/
void updateEncoders(void){
	uint16_t u_count_r,u_count_l;	// レジスタから保存用
	int16_t count_r,count_l;		// 戻り値用の変数

	u_count_l = TIM3->CNT;		// 左エンコーダの値を取り出す
	u_count_r = TIM2->CNT;		// 右エンコーダの値を取り出す

	TIM3->CNT = 0;
	TIM2->CNT = 0;
	// 値が逆回転していたら負に変換する
	if(u_count_l > 32767)	count_l = (int16_t)(65536 - u_count_l) *( -1);
	else					count_l = (int16_t)u_count_l;
	if(u_count_r > 32767)	count_r = (int16_t)(65536 - u_count_r) *( -1);
	else					count_r = (int16_t)u_count_r;

	// 出力するための変数保存
	enc_pulse_left = count_l;
	enc_pulse_right = count_r;
	enc_pulse_sigma_left += count_l;
	enc_pulse_sigma_right += count_r;
}

/**
 * getEncoderData
* @brief エンコーダのパルスカウントを取得
* @param *TIMx 取得したいエンコーダ変数、左:TIM3,  右: TIM2
* @return パルスカウント数
*/
int32_t getEncoderData(uint8_t command){
	switch(command){
		case LEFT_PULSE:		return enc_pulse_left; 			break;
		case RIGHT_PULSE:		return enc_pulse_right;			break;
		case LEFT_SIGMA_PULSE:	return enc_pulse_sigma_left; 	break;
		case RIGHT_SIGMA_PULSE:	return enc_pulse_sigma_right;	break;
	}
	return 0;	// 使うことないけど念のため
}


