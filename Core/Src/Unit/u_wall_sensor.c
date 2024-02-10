/*
 * u_wall_sensor.c
 *
 *  Created on: Feb 3, 2024
 *      Author: sssho
 */
#include "Unit/u_wall_sensor.h"

#include "Device/d_TLA2518.h"
#include "Device/d_indicator.h"
#include "Device/d_basic_timer.h"

// 主にADCのcha番号に対応したID, TLA2518を使う前提のアサイン
enum{
	SENSOR_ID_NULL_0 = 0,
	SENSOR_ID_NULL_1,
	SENSOR_ID_FRONT_RIGHT,
	SENSOR_ID_RIGHT,
	SENSOR_ID_NULL_4,
	SENSOR_ID_NULL_5,
	SENSOR_ID_LEFT,
	SENSOR_ID_FRONT_LEFT
}TLA_IDs;


#define SENSOR_NUMBER 4

tla2518_t offset_data[SENSOR_NUMBER];
tla2518_t sensor_data[SENSOR_NUMBER];

/**
* @brief
* @details　今回のクラスを使うための初期化処理、AkatsukiではDriveが既に初期化された後に呼び出された前提で開発
*/
void uws_initWallSensor(){
	// 初期化します
	for(int8_t i=0;i<SENSOR_NUMBER;i++){
			offset_data[i].value = 0;
			offset_data[i].id = 99;
			sensor_data[i].value = 0;
			sensor_data[i].id = 99;
	}
	// 壁センサ用に使うライブラリの処理
	dtla_initTLA2518();
}

/**
* @brief
* @details　タイマ割込みで呼ばれ、主に取得処理を行う。将来的には壁切れや壁アリの処理もここでやる。
*/
void uws_updateWallSensor(){
	// まず最初にLEDOFFのAD値を取得し、オフセット配列に代入してあげる
	di_lightSensorLEDs(LED_OFF, LED_OFF, LED_OFF, LED_OFF);
	dbt_waitUs(40);
	offset_data[ARRAY_ID_FR] = dtla_getAdcCH(SENSOR_ID_FRONT_RIGHT);
	offset_data[ARRAY_ID_R] = dtla_getAdcCH(SENSOR_ID_RIGHT);
	offset_data[ARRAY_ID_L] = dtla_getAdcCH(SENSOR_ID_LEFT);
	offset_data[ARRAY_ID_FL] = dtla_getAdcCH(SENSOR_ID_FRONT_LEFT);
	// 1stセット（FR,L)を取得し、生値を得た
	di_lightSensorLEDs(LED_OFF, LED_ON, LED_OFF, LED_ON);
	dbt_waitUs(40);
	sensor_data[ARRAY_ID_L] = dtla_getAdcCH(SENSOR_ID_LEFT);
	sensor_data[ARRAY_ID_FR] = dtla_getAdcCH(SENSOR_ID_FRONT_RIGHT);
	// 2ndセットを取得し、生値を得た
	di_lightSensorLEDs(LED_ON, LED_OFF, LED_ON, LED_OFF);
	dbt_waitUs(40);
	sensor_data[ARRAY_ID_R] = dtla_getAdcCH(SENSOR_ID_RIGHT);
	sensor_data[ARRAY_ID_FL] = dtla_getAdcCH(SENSOR_ID_FRONT_LEFT);
	// 修了したのでLED切っておく
	di_lightSensorLEDs(LED_OFF, LED_OFF, LED_OFF, LED_OFF);
}

/**
* @brief ほぼセンサ値ゲッター。
* @param センサ値を格納したいアドレス、基本は要素数4以上の配列
* @details　差分フィルタや移動平均フィルタが必要ならここでやる。
*/
void uws_containSensorValue(tla2518_t* temp_addr){
	// 配列が必要な大きさでなければ弾く
	if(sizeof(temp_addr) <= SENSOR_NUMBER)	return;
	//更新し処理されたセンサ値を引数のアドレスに格納してあげる
	for(uint8_t i=0;i<SENSOR_NUMBER;i++){
		temp_addr[i].value = sensor_data[i].value - offset_data[i].value;
		temp_addr[i].id = sensor_data[i].id;
	}
}
