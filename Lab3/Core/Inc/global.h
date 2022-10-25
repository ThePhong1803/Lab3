/*
 * global.h
 *
 *  Created on: Oct 25, 2022
 *      Author: PC
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "timer.h"
#include "input_reading.h"
//#define HARDWARE

#define INIT 		0
#define AUTO_RED 	2
#define AUTO_YELLOW 3
#define AUTO_GREEN  4

#define MODIFY_RED		12
#define MODIFY_YELLOW  	13
#define MODIFY_GREEN   	14

extern int status;
extern int lastState;
extern int mode;

extern int time_input;
extern int red_duration;
extern int yellow_duration;
extern int green_duration;

void systemInit();

#endif /* INC_GLOBAL_H_ */