/*
 * interrupts.h
 *
 * Created: 10/11/2022 2:43:36 AM
 *  Author: abosa
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

/*INTERRUPTS REGISTERS*/
#define MCUCR *((volatile uint8_t *)0x55) 
#define MCUCSR *((volatile uint8_t *)0x54)
#define GIFR *((volatile uint8_t *)0x5A)  
#define GICR *((volatile uint8_t *)0x5B)  


///////////Vectors////////////
#define EXT_INT_0 __vector_1
#define EXT_INT_1 __vector_2

/////Enable interrupts///////
#define sei()  __asm__ __volatile__ ("sei" ::: "memory")
#define cli()  __asm__ __volatile__ ("cli" ::: "memory")

//Rising edge
#define RISING_EDGE_SETUP() MCUCR|= (1<<1) | (1<<0)

//Setup use INT0
#define SETUP_INT0() GICR|=(1<<6)


//ISR macro
#define ISR(INT_VECT) \
void INT_VECT(void) __attribute__ ((signal,used)); \
void INT_VECT(void)




#endif /* INTERRUPTS_H_ */

