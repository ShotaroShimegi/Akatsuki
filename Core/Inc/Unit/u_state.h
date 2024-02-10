/*
 * u_state.h
 *
 *  Created on: Dec 30, 2023
 *      Author: sssho
 */

#ifndef INC_UNIT_U_STATE_H_
#define INC_UNIT_U_STATE_H_

typedef struct{
	float pos_x,pos_y;						// スタートを原点とした相対位置
	float distance_mm;						// 総走行距離
	float theta_deg,theta_rad;				// 角度
	float velocity_mps;						// 速度
	float omega_radps;						// 角速度
	float accel_mpss;						// 加速度
	float omega_accel_radpss;				// 角加速度
	uint16_t dist_right_wall,dist_left_wall;// 左右壁との距離
	uint16_t dist_front_wall;				// 前壁との距離

}MouseState;

/*
 * センサ類から機体の情報管理を行う
 * あくまでセンシングのみ、目標値計算や制御計算は別途行う
 */

void ust_initializeState();
void ust_updateState();
void ust_containState();

#endif /* INC_UNIT_U_STATE_H_ */
