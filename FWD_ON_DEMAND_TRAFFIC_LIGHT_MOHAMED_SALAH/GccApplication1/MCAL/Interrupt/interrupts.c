/*
 * interrupts.c
 *
 * Created: 10/11/2022 2:43:18 AM
 *  Author: Mohamed Salah
 */ 
#include "interrupts.h"
#include "../Lib/BIT_MATH.h"

void INT0_init_rising(void)
{
	//  Enable global interrupt(setting bit 7 in status register to 1
	sei();  
	
	// Setting sense on the rising edge
	MCUCR_REG|=(1 << 0) | (1 << 1);
	
	// Enable INT0
	SET_BIT(GICR_REG,6);
}
