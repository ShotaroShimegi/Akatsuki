/*
 * d_motor.c
 *
 *  Created on: Nov 4, 2023
 *      Author: sssho
 */
#include"Device/d_motor.h"

#include"main.h"

int8_t motor_left_dir = 0;
int8_t motor_right_dir = 0;
uint8_t duty_left_abs = 0;
uint8_t duty_right_abs = 0;

/**
* @brief main loop 	モータ回転を有効化する。最初はdutyを1%にしておく
* 		 TIM5 -> 左Duty_HIGH区
*/
void dm_enableMotors(void){
	//モータを動かし始める
	LL_TIM_EnableIT_CC1(TIM5);
	LL_TIM_EnableIT_CC2(TIM5);
	LL_TIM_EnableIT_UPDATE(TIM5);

	LL_TIM_CC_EnableChannel(TIM5, LL_TIM_CHANNEL_CH1);
	LL_TIM_CC_EnableChannel(TIM5, LL_TIM_CHANNEL_CH2);

	LL_TIM_SetAutoReload(TIM5,200-1);
	LL_TIM_OC_SetCompareCH1(TIM5, 10-1);
	LL_TIM_OC_SetCompareCH2(TIM5, 10-1);
	LL_TIM_SetCounter(TIM5, 0);

	LL_TIM_EnableCounter(TIM5);

//	LL_TIM_EnableAllOutputs(TIM5);	//必要？
}

/**
* @brief 左モータを静止する。急速に止まるはず。
*/
void dm_brakeLeftMotors(void){
	// 左モータについて
	LL_GPIO_SetOutputPin(MOTOR_L_IN1_GPIO_Port,MOTOR_L_IN1_Pin);
	LL_GPIO_SetOutputPin(MOTOR_L_IN2_GPIO_Port,MOTOR_L_IN2_Pin);
}

/**
* @brief 右モータを静止する。急速に止まるはず。
*/
void dm_brakeRightMotors(void){
	// 左モータについて
	LL_GPIO_SetOutputPin(MOTOR_R_IN1_GPIO_Port,MOTOR_R_IN1_Pin);
	LL_GPIO_SetOutputPin(MOTOR_R_IN2_GPIO_Port,MOTOR_R_IN2_Pin);
}

/**
* @brief モータを静止する。急速に止まるはず。
*/
void dm_brakeMotors(void){
	dm_brakeLeftMotors();
	dm_brakeRightMotors();
}
/**
* @brief モータを静止する。慣性で回るはず
*/
void dm_smoothMotors(void){
	// 左モータについて
	LL_GPIO_ResetOutputPin(MOTOR_L_IN1_GPIO_Port,MOTOR_L_IN1_Pin);
	LL_GPIO_ResetOutputPin(MOTOR_L_IN2_GPIO_Port,MOTOR_L_IN2_Pin);
	// 右モータについて
	LL_GPIO_ResetOutputPin(MOTOR_R_IN1_GPIO_Port,MOTOR_R_IN1_Pin);
	LL_GPIO_ResetOutputPin(MOTOR_R_IN2_GPIO_Port,MOTOR_R_IN2_Pin);
}
/**
* @brief モータを静止する。急速に止まるはず。
* @param 回転方向, 0:Forward, 1:Back
*/
void dm_driveRightMotor(uint8_t dir){
	if(dir == FORWARD){
		LL_GPIO_ResetOutputPin(MOTOR_R_IN1_GPIO_Port,MOTOR_R_IN1_Pin);
		LL_GPIO_SetOutputPin(MOTOR_R_IN2_GPIO_Port,MOTOR_R_IN2_Pin);
	}else{
		LL_GPIO_SetOutputPin(MOTOR_R_IN1_GPIO_Port,MOTOR_R_IN1_Pin);
		LL_GPIO_ResetOutputPin(MOTOR_R_IN2_GPIO_Port,MOTOR_R_IN2_Pin);
	}
}
void dm_driveLeftMotor(uint8_t dir){
	if(dir == FORWARD){
		LL_GPIO_ResetOutputPin(MOTOR_L_IN1_GPIO_Port,MOTOR_L_IN1_Pin);
		LL_GPIO_SetOutputPin(MOTOR_L_IN2_GPIO_Port,MOTOR_L_IN2_Pin);
	}else{
		LL_GPIO_SetOutputPin(MOTOR_L_IN1_GPIO_Port,MOTOR_L_IN1_Pin);
		LL_GPIO_ResetOutputPin(MOTOR_L_IN2_GPIO_Port,MOTOR_L_IN2_Pin);
	}
}

/**
* @brief モータ回転を無効化する。duty関連はHIGHにしておく。
*/
void dm_disableMotors(void){
	// 完全に一回止める
	LL_TIM_DisableCounter(TIM5);

	LL_TIM_DisableIT_UPDATE(TIM5);
	LL_TIM_DisableIT_CC1(TIM5);
	LL_TIM_DisableIT_CC2(TIM5);

	// 念のため、モータの設定を止めておく
	dm_brakeMotors();
}

/**
* @brief 割込み処理で呼ばれる関数、
*/
void dm_driveMotors(int8_t duty_left, int8_t duty_right){
	// 符号から回転方向を変数に保存
	if(duty_left > 0)	{
		motor_left_dir = FORWARD;
		duty_left_abs = (uint8_t)duty_left;
	}else{
		motor_left_dir = BACK;
		duty_left_abs = (uint8_t)(-duty_left);
	}

	if(duty_right > 0)	{
		motor_right_dir = FORWARD;
		duty_right_abs = (uint8_t)duty_right;
	}
	else				{
		motor_right_dir = BACK;
		duty_right_abs = (uint8_t)(-duty_right);
	}

	// 左dutyの最大値、最小値を確認し保存
	if(duty_left_abs > DUTY_MAX)		duty_left_abs = DUTY_MAX;
	else if(duty_left_abs < DUTY_MIN)	duty_left_abs = DUTY_MIN;
	// 右dutyの最大値、最小値を確認し保存
	if(duty_right_abs > DUTY_MAX)		duty_right_abs = DUTY_MAX;
	else if(duty_right_abs < DUTY_MIN)	duty_right_abs = DUTY_MIN;
}
/**
* @brief PWMを生成し、LOW周期修了タイミングで呼ばれる関数
* @param 0xf0 -> 左モータ、0x0f -> 右モータ
* @return 次のタイマのcounter.period
*/
uint16_t dm_updateMotors(uint8_t which){
	switch(which){
		case LEFT_MOTOR:
			dm_driveLeftMotor(motor_left_dir);
			return 2*duty_left_abs;
			break;
		case RIGHT_MOTOR:
			dm_driveRightMotor(motor_right_dir);
			return 2*duty_right_abs;
			break;
		default:
			return 10;
			break;
	}
	return 0;
}
