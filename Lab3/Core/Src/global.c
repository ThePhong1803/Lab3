/*
 * global.c
 *
 *  Created on: Oct 25, 2022
 *      Author: PC
 */


#include "global.h"

int status = INIT;
int lastState = INIT;

int red_duration    = 500; //5 seconds
int yellow_duration = 200; //2 seconds
int green_duration  = 300; //3 seconds

int time_input = 1;
int mode = 1;


void systemInit(){
	initButton();
	GPIOB -> ODR = 0xffff;
	setTimer0(50);
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);

	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, RESET);
	HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, SET);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);

	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
	HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, SET);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, RESET);
}
