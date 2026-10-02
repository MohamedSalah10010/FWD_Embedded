/*
 * Timer_REG.h
 *
 * Created: 9/14/2022 11:37:25 PM
 *  Author: Mohamed Salah
 */ 


#ifndef TIMER_REG_H_
#define TIMER_REG_H_

//////////TIMER0 REGISTERS/////////
#define TCCR0_REG  *((volatile uint8_t*)0X53) // controlling mode
#define TCNT0_REG   *((volatile uint8_t*)0X52) // data reg
#define TIFR_REG   *((volatile uint8_t*)0X58) // interrupt reg


#endif /* TIMER_REG_H_ */
