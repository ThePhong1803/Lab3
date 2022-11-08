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
		LED7PORT -> ODR |= 0x00ff;
		LED7PORT -> ODR &= 0xff40;
	}
	if(num == 1){
		LED7PORT -> ODR |= 0x00ff;
		LED7PORT -> ODR &= 0xff79;
	}
	if(num == 2){
		LED7PORT -> ODR |= 0x00ff;
		LED7PORT -> ODR &= 0xff24;
	}
	if(num == 3){
		LED7PORT -> ODR |= 0x00ff;
		LED7PORT -> ODR &= 0xff30;
	}
	if(num == 4){
		LED7PORT -> ODR |= 0x00ff;
		LED7PORT -> ODR &= 0xff19;
	}
	if(num == 5){
		LED7PORT -> ODR |= 0x00ff;
		LED7PORT -> ODR &= 0xff12;
	}
	if(num == 6){
		LED7PORT -> ODR |= 0x00ff;
		LED7PORT -> ODR &= 0xff02;
	}
	if(num == 7){
		LED7PORT -> ODR |= 0x00ff;
		LED7PORT -> ODR &= 0xff78;
	}
	if(num == 8){
		LED7PORT -> ODR |= 0x00ff;
		LED7PORT -> ODR &= 0xff80;
	}
	if(num == 9){
		LED7PORT -> ODR |= 0x00ff;
		LED7PORT -> ODR &= 0xff90;
	}
}

void display7SEG2(int num){
	if(num == 0){
		LED7PORT -> ODR |= 0xff00;
		LED7PORT -> ODR &= 0x40ff;
	}
	if(num == 1){
		LED7PORT -> ODR |= 0xff00;
		LED7PORT -> ODR &= 0x79ff;
	}
	if(num == 2){
		LED7PORT -> ODR |= 0xff00;
		LED7PORT -> ODR &= 0x24ff;
	}
	if(num == 3){
		LED7PORT -> ODR |= 0xff00;
		LED7PORT -> ODR &= 0x30ff;
	}
	if(num == 4){
		LED7PORT -> ODR |= 0xff00;
		LED7PORT -> ODR &= 0x19ff;
	}
	if(num == 5){
		LED7PORT -> ODR |= 0xff00;
		LED7PORT -> ODR &= 0x12ff;
	}
	if(num == 6){
		LED7PORT -> ODR |= 0xff00;
		LED7PORT -> ODR &= 0x02ff;
	}
	if(num == 7){
		LED7PORT -> ODR |= 0xff00;
		LED7PORT -> ODR &= 0x78ff;
	}
	if(num == 8){
		LED7PORT -> ODR |= 0xff00;
		LED7PORT -> ODR &= 0x80ff;
	}
	if(num == 9){
		LED7PORT -> ODR |= 0xff00;
		LED7PORT -> ODR &= 0x90ff;
	}
}

//input pointer for 2 set of 2 7-segment led
int * set1;
int * set2;

int led_index = 0;

void update7Segment(){
	if(isTimer0Expired()){
		setTimer0(10);
		switch (led_index) {
			case 0:
				//turn on time count display led
				LED7PORT->ODR = 0xffff;
				display7SEG1(*set1 % 10);
				display7SEG2(*set1 / 10);
				HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
				HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
				break;
			case 1:
				//turn on mode display led
				LED7PORT->ODR = 0xffff;
				display7SEG1(*set2 % 10);
				display7SEG2(*set2 / 10);
				HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
				HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
				break;
			default:
				break;
		}
		led_index = (led_index + 1) % 2;
	}
}
