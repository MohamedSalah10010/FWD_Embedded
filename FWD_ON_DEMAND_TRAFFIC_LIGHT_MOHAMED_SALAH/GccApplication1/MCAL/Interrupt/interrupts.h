/*
 * interrupts.h
 *
 * Created: 10/11/2022 2:43:36 AM
 *  Author: Mohamed Salah
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

#include "interrupts_Reg.h"
///////////Vectors////////////
#define EXT_INT_0 __vector_1

#define EXT_INT_1 __vector_2

#define EXT_INT_3 __vector_3
/////Set global interrupt, set the 7th bit in status reg///////
#define sei()  __asm__ __volatile__ ("sei" ::: "memory")

//////Clear global interrupt, clear the 7th bit in status reg///////
#define cli()  __asm__ __volatile__ ("cli" ::: "memory")

////ISR definition //////////

#define ISR(INT_VECT) void INT_VECT(void) __attribute__ ((signal,used)); void INT_VECT(void)

////// initializing functions prototypes///////////

//void iNT0_RISISNG(void); 
void INT0_init_rising(void); 







#endif /* INTERRUPTS_H_ */

