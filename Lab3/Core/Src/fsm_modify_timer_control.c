/*
 * fsm_modify_timer_control.h
 *
 *  Created on: Oct 26, 2022
 *      Author: PC
 */


#include "fsm_modify_timer_control.h"

void fsm_modify_timer_control(){
	switch(status){
		case MODIFY_RED:
			//set mode to display
			mode = 2;
			if(isTimer1Expired()) {
				setTimer1(10);
				toggleRed1();
				toggleRed2();
			}

			//check if user want to apply new duration and return auto mode
			if(isButtonPressed(RETURN)) {
				//set new duration for red led
				red_duration = time_input;
				setTimer1(red_duration * 100);
				//return the the last auto status
				status = lastState;
			}

			//check if user want to increase time
			if(isButtonPressed(SET_TIME)) {
				time_input = (time_input + 1) % 100; //max value is 99
				if(time_input == 0) time_input = 1; //0 is invalid value
			}

			//check if user want to change mode
			if(isButtonPressed(CONTROL_MODE)) status = MODIFY_YELLOW;
			break;
		case MODIFY_YELLOW:
			//set mode to display
			mode = 3;
			if(isTimer1Expired()) {
				setTimer1(10);
				toggleYellow1();
				toggleYellow2();
			}

			//check if user want to apply new duration and return auto mode
			if(isButtonPressed(RETURN)){
				//set new duration for yellow led
				yellow_duration = time_input;
				setTimer1(yellow_duration * 100);
				//return to the last auto status
				status = lastState;
			}

			//check if user want to increase time
			if(isButtonPressed(SET_TIME)) {
				time_input = (time_input + 1) % 100; //99 is the max value
				if(time_input == 0) time_input = 1; //0 is invalid value
			}

			//check if user want to change mode
			if(isButtonPressed(CONTROL_MODE)) status = MODIFY_GREEN;
			break;
		case MODIFY_GREEN:

			//set mode to display
			mode = 4;
			if(isTimer1Expired()) {
				setTimer1(10);
				toggleGreen1();
				toggleGreen2();
			}
			//check if user want to apply new duration and return auto mode
			if(isButtonPressed(RETURN)) {
				//set new duration for green led
				green_duration = time_input;
				setTimer1(green_duration * 100);
				//return to the last auto state
				status = lastState;
			}

			//check if user want to increase time
			if(isButtonPressed(SET_TIME)) {
				time_input = (time_input + 1) % 100; //99 is the max value
				if(time_input == 0) time_input = 1; //1 is invalid value
			}

			//check if user want to change mode
			if(isButtonPressed(CONTROL_MODE)) status = lastState;
			break;
		default:
			break;
	}
}