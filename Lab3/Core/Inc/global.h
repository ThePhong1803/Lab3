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

#define INIT 		1
#define AUTO_RED 	2
#define AUTO_YELLOW 3
#define AUTO_GREEN  4

#define MODIFY_RED1			12
#define MODIFY_YELLOW1  	13
#define MODIFY_GREEN1   	14
#define MODIFY_RED2         15
#define MODIFY_YELLOW2		16
#define MODIFY_GREEN2		17

#define WAIT				18

extern int timeCountdown1;
extern int timeCountdown2;

extern int status1;
extern int lastState1;

extern int status2;
extern int lastState2;

extern int status3;

extern int returnFlag1;
extern int returnFlag2;

extern int mode;
extern int time_input;

extern int red_duration1;
extern int yellow_duration1;
extern int green_duration1;

extern int red_duration2;
extern int yellow_duration2;
extern int green_duration2;

extern int * set1;
extern int * set2;

void systemInit();

#endif /* INC_GLOBAL_H_ */
