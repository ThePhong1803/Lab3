/*
 * timer.c
 *
 *  Created on: Oct 25, 2022
 *      Author: PC
 */
#include "timer.h"

int timer0_cnt = 0;
int timer1_cnt = 0;

int timer0_flag = 0;
int timer1_flag = 0;

void setTimer0(int duration){
	timer0_cnt = duration;
	timer0_flag = 0;
}

void setTimer1(int duration){
	timer1_cnt = duration;
	timer1_flag = 0;
}

void clearTimer0(){
	timer0_cnt = 0;
	timer0_flag = 0;
}

void clearTimer1(){
	timer1_cnt = 0;
	timer1_flag = 0;
}


void timerRun(){
	if(timer0_cnt > 0){
		timer0_cnt--;
		if(timer0_cnt <= 0) timer0_flag = 1;
	}
	if(timer1_cnt > 0){
		timer1_cnt--;
		if(timer1_cnt <= 0) timer1_flag = 1;
	}
}

int isTimer0Expired(){
	if(timer0_flag == 1){
		timer0_flag = 0;
		return 1;
	} else return 0;
}

int isTimer1Expired(){
	if(timer1_flag == 1){
		timer1_flag = 0;
		return 1;
	} else return 0;
}