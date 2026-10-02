/*
 * Interrupts.h
 *
 * Created: 10/12/2022 4:26:15 PM
 *  Author: Mohamed Salah
 */ 


#ifndef INTERRUPTS_REG_H_
#define INTERRUPTS_REG_H_
#include "../Lib/STD_TYPES.h"

/*INTERRUPTS REGISTERS*/
#define MCUCR_REG *((volatile uint8_t *)0x55)
#define MCUCSR_REG *((volatile uint8_t *)0x54)
#define GIFR_REG *((volatile uint8_t *)0x5A)
#define GICR_REG *((volatile uint8_t *)0x5B)




#endif /* INTERRUPTS_REG_H_ */