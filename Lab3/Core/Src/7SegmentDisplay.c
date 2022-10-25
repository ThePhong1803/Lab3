/*
 * 7SegmentDisplay.c
 *
 *  Created on: Oct 25, 2022
 *      Author: PC
 */


#include "7SegmentDisplay.h"
#include "global.h"

void display7SEG1(int num){
	if(num == 0){
		GPIOB -> ODR &= 0xff00;
		GPIOB -> ODR |= 0x0040;
	}
	if(num == 1){
		GPIOB -> ODR &= 0xff00;
		GPIOB -> ODR |= 0x0079;
	}
	if(num == 2){
		GPIOB -> ODR &= 0xff00;
		GPIOB -> ODR |= 0x0024;
	}
	if(num == 3){
		GPIOB -> ODR &= 0xff00;
		GPIOB -> ODR |= 0x0030;
	}
	if(num == 4){
		GPIOB -> ODR &= 0xff00;
		GPIOB -> ODR |= 0x0019;
	}
	if(num == 5){
		GPIOB -> ODR &= 0xff00;
		GPIOB -> ODR |= 0x0012;
	}
	if(num == 6){
		GPIOB -> ODR &= 0xff00;
		GPIOB -> ODR |= 0x0002;
	}
	if(num == 7){
		GPIOB -> ODR &= 0xff00;
		GPIOB -> ODR |= 0x0078;
	}
	if(num == 8){
		GPIOB -> ODR &= 0xff00;
		GPIOB -> ODR |= 0x0080;
	}
	if(num == 9){
		GPIOB -> ODR &= 0xff00;
		GPIOB -> ODR |= 0x0090;
	}
}

void display7SEG2(int num){
	if(num == 0){
		GPIOB -> ODR &= 0x00ff;
		GPIOB -> ODR |= 0x4000;
	}
	if(num == 1){
		GPIOB -> ODR &= 0x00ff;
		GPIOB -> ODR |= 0x7900;
	}
	if(num == 2){
		GPIOB -> ODR &= 0x00ff;
		GPIOB -> ODR |= 0x2400;
	}
	if(num == 3){
		GPIOB -> ODR &= 0x00ff;
		GPIOB -> ODR |= 0x3000;
	}
	if(num == 4){
		GPIOB -> ODR &= 0x00ff;
		GPIOB -> ODR |= 0x1900;
	}
	if(num == 5){
		GPIOB -> ODR &= 0x00ff;
		GPIOB -> ODR |= 0x1200;
	}
	if(num == 6){
		GPIOB -> ODR &= 0x00ff;
		GPIOB -> ODR |= 0x0200;
	}
	if(num == 7){
		GPIOB -> ODR &= 0x00ff;
		GPIOB -> ODR |= 0x7800;
	}
	if(num == 8){
		GPIOB -> ODR &= 0x00ff;
		GPIOB -> ODR |= 0x8000;
	}
	if(num == 9){
		GPIOB -> ODR &= 0x00ff;
		GPIOB -> ODR |= 0x9000;
	}
}

int led_index = 0;

void update7Segment(){
	if(isTimer0Expired()){
		setTimer0(50);
		switch (led_index) {
			case 0:
				//turn on time count display led
				display7SEG1(mode % 10);
				display7SEG2(mode/ 10);
				HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
				HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
				break;
			case 1:
				//turn on mode display led
				display7SEG1(time_input % 10);
				display7SEG2(time_input / 10);
				HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
				HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
				break;
			default:
				break;
		}
		led_index = (led_index + 1) % 2;
	}
}
