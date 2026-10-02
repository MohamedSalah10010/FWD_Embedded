/*
 * Timer.h
 *
 * Created: 9/14/2022 10:51:54 PM
 *  Author: Mohamed Salah
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "Timer_REG.h"
#include "../DIO/DIO_INTERFACE.h"

void timer_init(); // initiate normal mode

void delay(uint32_t duration_millisec); // set delay in milliseconds 



#endif /* TIMER_H_ */