/*
 * global.c
 *
 *  Created on: Oct 25, 2022
 *      Author: PC
 */


#include "global.h"

int status1 = INIT;
int lastState1 = INIT;

int status2 = INIT;
int lastState2 = INIT;

int status3 = WAIT;

int red_duration1    = 500; //5 seconds
int yellow_duration1 = 200; //2 seconds
int green_duration1  = 300; //3 seconds

int red_duration2    = 500; //5 seconds
int yellow_duration2 = 200; //2 seconds
int green_duration2  = 300; //3 seconds

int time_input = 1;
int mode = 1;

int timeCountdown1 = 0;
int timeCountdown2 = 0;

int returnFlag1 = 0;
int returnFlag2 = 0;


void systemInit(){
	initButton();
	GPIOB -> ODR = 0xffff;
	setTimer0(10);
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);

	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, RESET);
	HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, SET);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);

	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
	HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, SET);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, RESET);
}
