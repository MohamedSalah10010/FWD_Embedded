/*
 * test_interrupt.c
 *
 * Created: 10/14/2022 8:07:45 PM
 *  Author: abosa
 */ 
#include "interrupts.h"
#include "../../ECUAL/LED/LED.h"
#include "../../ECUAL/Button/Button.h"
/*
 static uint8_t x=0;
 
	 int main(void){
	 
	 INT0_init_rising();
		 
	 	Button_init(PORTD,2);
 		LED_init(PORTC,0);
	 	LED_init(PORTC,2);
	 	
	 	while(1){
	 		
	 	if (x==1){
	 		LED_on(PORTC,0);
	 	}
	 	else LED_on(PORTC,2);
	 	}
	 }
	 
	 ISR(EXT_INT_0){
	 	if (x==0){
	 		x=1;
	 	}
	 	else {x=0;}
	 	
	 	}
		 
	*/