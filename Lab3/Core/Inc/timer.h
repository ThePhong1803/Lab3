/*
 * timer.h
 *
 *  Created on: Oct 25, 2022
 *      Author: PC
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include "main.h"
#include "input_reading.h"

void setTimer0(int duration);
void setTimer1(int duration);

void clearTimer0();
void clearTimer1();

int isTimer0Expired();
int isTimer1Expired();

void timerRun();

#endif /* INC_TIMER_H_ */
