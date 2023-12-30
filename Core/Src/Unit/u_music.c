/*
 * u_music.c
 *
 *  Created on: Nov 28, 2023
 *      Author: sssho
 */

#include "Unit/u_music.h"

#include "Device/d_basic_timer.h"
#include "Device/d_buzzer.h"

void um_MelodySummer(void){
	dbz_Melody(g6,100);
	dbz_Melody(c7,100);
	dbz_Melody(d7,100);
	dbz_Melody(e7,100);
	dbz_Melody(d7,100);
	dbt_waitMs(50);
	dbz_Melody(c7,50);
	dbt_waitMs(50);
	dbz_Melody(c7,200);
}

void um_MelodyRayearth(void){
	dbz_Melody(f5,100);
	dbt_waitMs(10);
	dbz_Melody(f5,600);
	dbz_Melody(c6,400);
	dbz_Melody(d6,200);
	dbz_Melody(a5h,600);
}

void um_MelodyGoal(void){
	dbz_Melody(g6,300);
	dbz_Melody(f6,300);
	dbz_Melody(e6,300);
}

void um_MelodyUrara(void){
	dbz_Melody(d7,100);
	dbz_Melody(a6,100);
	dbt_waitMs(10);
	dbz_Melody(a6,200);
	dbt_waitMs(50);

	dbz_Melody(d7,100);
	dbz_Melody(a6,100);
	dbt_waitMs(10);
	dbz_Melody(a6,200);
	dbt_waitMs(50);

	dbz_Melody(d7,100);
	dbz_Melody(c7,100);
	dbz_Melody(d7,100);
	dbz_Melody(c7,100);
	dbz_Melody(a6,200);
	dbt_waitMs(50);

}

void um_MelodyMrLawrence() {
	dbz_Melody(d7,100);
	dbz_Melody(e7,100);
	dbz_Melody(d7,100);
	dbz_Melody(a6,100);
	dbz_Melody(d7,100);

	dbt_waitMs(400);

	dbz_Melody(d7,100);
	dbz_Melody(e7,100);
	dbz_Melody(d7,100);
	dbz_Melody(e6,100);
	dbz_Melody(g7,100);
	dbz_Melody(e6,100);
	dbz_Melody(d7,100);
	dbz_Melody(e7,100);
	dbz_Melody(d7,100);
	dbz_Melody(c7,100);
	dbz_Melody(a6,100);
}

void um_MelodyNatsumatsuri() {
	dbz_Melody(d6,200);
	dbz_Melody(f6,200);
	dbz_Melody(g6,200);
	dbz_Melody(f6,100);
	dbz_Melody(g6,100);
	dbz_Melody(a6,200);
	dbz_Melody(c6,200);
	dbz_Melody(d6,200);
}

void um_MelodyKurenai(void){
	dbz_Melody(c7,300);
	dbt_waitMs(10);
	dbz_Melody(c7,100);
	dbz_Melody(b6,100);
	dbz_Melody(c7,300);
	dbt_waitMs(10);
	dbz_Melody(d6,100);
	dbz_Melody(e7,300);
	dbz_Melody(d7,100);
	dbz_Melody(c7,100);
	dbz_Melody(b6,300);
}

void um_MelodyYamato(){
	dbz_Melody(e6,100);
	dbt_waitMs(10);
	dbz_Melody(e6,200);
	dbz_Melody(f6,100);
	dbz_Melody(e6,200);
	dbz_Melody(c6,200);

	dbz_Melody(f6,400);
	dbz_Melody(e6,400);
	dbz_Melody(d6,400);
}
