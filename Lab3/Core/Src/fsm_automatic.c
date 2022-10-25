/*
 * fsm_automatic.c
 *
 *  Created on: Oct 25, 2022
 *      Author: PC
 */


#include "fsm_automatic.h"

void fsm_automatic_run(){
	switch(status){
		case INIT:
			//TODO
			setRedLed1();
			status = AUTO_RED;
			lastState = status;
			setTimer1(red_duration);
			mode = 1;
			break;

		case AUTO_RED:
			//TODO
			setRedLed1();
			mode = 1;
			if(isTimer1Expired() == 1){
				setTimer1(green_duration);
				status = AUTO_GREEN;
			}

			if(isButtonPressed(0)){
				lastState = status;
				status = MODIFY_RED;
				clearTimer1();
				setTimer1(100);
			}
			break;

		case AUTO_GREEN:
			//TODO
			mode = 1;
			setGreenLed1();
			if(isTimer1Expired() == 1){
				setTimer1(yellow_duration);
				status = AUTO_YELLOW;
			}

			if(isButtonPressed(0)){
				lastState = status;
				status = MODIFY_RED;
				clearTimer1();
				setTimer1(100);
			}
			break;

		case AUTO_YELLOW:
			//TODO
			mode = 1;
			setYellowLed1();
			if(isTimer1Expired() == 1){
				setTimer1(red_duration);
				status = AUTO_RED;
			}

			if(isButtonPressed(0)){
				lastState = status;
				status = MODIFY_RED;
				clearTimer1();
				setTimer1(100);
			}
			break;

		default:
			break;
	}
}