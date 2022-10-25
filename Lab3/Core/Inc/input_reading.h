/*
 * button.h
 *
 *  Created on: Oct 25, 2022
 *      Author: PC
 */

#ifndef INC_READING_INPUT_H_
#define INC_READING_INPUT_H_

#include "main.h"

// we aim to work with more than one buttons
#define NO_OF_BUTTONS 3
// timer interrupt duration is 10ms , so to pass 1 second ,
// we need to jump to the interrupt service routine 100 time
#define DURATION_FOR_AUTO_INCREASING 	100

//define button state
#define BUTTON_IS_PRESSED 				GPIO_PIN_RESET
#define BUTTON_IS_RELEASED 				GPIO_PIN_SET

//define button flags
#define BUTTON_FLAG_SET					1
#define BUTTON_FLAG_CLEAR 				0

//define button function name
#define CONTROL_MODE 					0
#define SET_TIME     					1
#define RETURN       					2

void initButton();
void button_reading(void);
unsigned char isButtonPressed(unsigned char index);
unsigned char isButtonPressed1s(unsigned char index);

#endif /* INC_READING_INPUT_H_ */