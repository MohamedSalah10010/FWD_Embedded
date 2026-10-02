/*
 * Timer.c
 *
 * Created: 9/14/2022 10:52:12 PM
 *  Author: Mohamed Salah
 */ 

#include <math.h>
#include "Timer.h"
void timer_init(){
	TCCR0_REG = 0x00; //set normal mode for timer0 and stop it
	TCNT0_REG=0x00; // setting initial value for timer0
}


void delay(uint32_t duration){
	
	timer_init();
	uint32_t N_OverFlow,Timer_Initial,overFlow_Flag=0, duration_millisec=duration;	
	double T_max , T_tick;
	
/*  max delay 0.032 milliseconds at 8 MHz no prescaler and 8-bit timer register
 
 
	T_maxdelay= T_tick * 2^(sizeof timer_regisetr)=(1/8 MHz)*2^(8) ;	
*/
	
	 
/******  with 1024 prescaler ********/
T_max= 32.768 ; // ms
T_tick = 0.128; //ms
	
	if(duration_millisec<T_max){
		Timer_Initial = (T_max-duration_millisec)/T_tick;
		N_OverFlow = 1;
		}
		
	else if(duration_millisec == (int)T_max){
		Timer_Initial=0;
		N_OverFlow=1;
		}
		
	else{
		N_OverFlow = ceil((double)duration_millisec/T_max);
		Timer_Initial = 256 - ((double)duration_millisec/T_tick)/N_OverFlow;		
	}
	TCNT0_REG = Timer_Initial;
	///// set prescaler to 1024
	SET_BIT(TCCR0_REG,0);
	SET_BIT(TCCR0_REG,2); 
	
	while(overFlow_Flag<N_OverFlow){
		while(READ_BIT(TIFR_REG,0)==0);
		//clear overflow flag
		SET_BIT(TIFR_REG,0);
		//increment counter
		overFlow_Flag++;
	}
	//Timer stop
	TCCR0_REG = 0x00;
}