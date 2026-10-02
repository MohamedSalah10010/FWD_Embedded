/*
 * app.c
 *
 * Created: 10/12/2022 8:42:38 PM
 *  Author: Mohamed Salah
 */ 

#include "app.h"
/*
void STOP(void){
	LED_off(LED_CAR_PORT,LED_CAR_GREEN);
	LED_off(LED_walking_PORT,LED_walking_RED);
	LED_off(LED_CAR_PORT,LED_CAR_YELLOW);
	LED_off(LED_walking_PORT,LED_walking_YELLOW);
	LED_off(LED_CAR_PORT,LED_CAR_RED);
	LED_off(LED_walking_PORT,LED_walking_GREEN);

}*/

void app_init(void){

	INT0_init_rising();
	
	Button_init(PORTD,2);// set button in INT0 pin
	

	/*initializing CAR TRAFFIC LIGHTS*/
	LED_init(LED_CAR_PORT,LED_CAR_GREEN);
	LED_init(LED_CAR_PORT,LED_CAR_YELLOW);
	LED_init(LED_CAR_PORT,LED_CAR_RED);

	LED_init(LED_walking_PORT,LED_walking_GREEN);
	LED_init(LED_walking_PORT,LED_walking_YELLOW);
	LED_init(LED_walking_PORT,LED_walking_RED);
	
}

ISR(EXT_INT_0){
	interrupt=ON;
}

void app_start(void){
	Normal();
}




void Normal(void){
	interrupt=OFF;
	
	while(1){
	/* Set normal mode ----> 
	1. green for 5 sec 
	2. then yellow blinks for 5 sec 
	3. then red for 5 sec 
	4. the yellow blinks for 5 sec      */
	
	/****car signal is green****/
	CAR_SIGNAL_STATE=GREEN;
	LED_on(LED_CAR_PORT,LED_CAR_GREEN);          
    LED_on(LED_walking_PORT,LED_walking_RED); 
	delay(time_millis);
	LED_off(LED_CAR_PORT,LED_CAR_GREEN);   
	LED_off(LED_walking_PORT,LED_walking_RED);
	if (interrupt==ON)pedestrian();
	
	/****car signal is yellow****/
	CAR_SIGNAL_STATE=YELLOW;
	_2_LED_blink(LED_CAR_PORT,LED_CAR_YELLOW,LED_walking_PORT,LED_walking_YELLOW,time_millis);
	LED_off(LED_CAR_PORT,LED_CAR_YELLOW);      
    LED_off(LED_walking_PORT,LED_walking_YELLOW);
	if (interrupt==ON)pedestrian();
	
	/****car signal is red****/
	CAR_SIGNAL_STATE=RED;
	LED_on(LED_CAR_PORT,LED_CAR_RED);
	LED_on(LED_walking_PORT,LED_walking_GREEN);
	delay(time_millis);
	LED_off(LED_CAR_PORT,LED_CAR_RED);	
	LED_off(LED_walking_PORT,LED_walking_GREEN);
	if (interrupt==ON)pedestrian();
	
	/****car signal is yellow****/
	CAR_SIGNAL_STATE=YELLOW;
	_2_LED_blink(LED_CAR_PORT,LED_CAR_YELLOW,LED_walking_PORT,LED_walking_YELLOW,time_millis);
	LED_off(LED_CAR_PORT,LED_CAR_YELLOW);	
	LED_off(LED_walking_PORT,LED_walking_YELLOW);
	if (interrupt==ON)pedestrian();
	}
}



void pedestrian(void){

	
	switch(CAR_SIGNAL_STATE){
		case GREEN: 
		LED_on(LED_CAR_PORT,LED_CAR_GREEN);
		LED_on(LED_walking_PORT,LED_walking_RED);
		delay(time_millis);
		LED_off(LED_CAR_PORT,LED_CAR_GREEN);
		LED_off(LED_walking_PORT,LED_walking_RED);
	
		_2_LED_blink(LED_CAR_PORT,LED_CAR_YELLOW,LED_walking_PORT,LED_walking_YELLOW,time_millis);
		LED_off(LED_CAR_PORT,LED_CAR_YELLOW);
		LED_off(LED_walking_PORT,LED_walking_YELLOW);
		
		LED_on(LED_CAR_PORT,LED_CAR_RED);
		LED_on(LED_walking_PORT,LED_walking_GREEN);
		delay(time_millis);
		LED_off(LED_CAR_PORT,LED_CAR_RED);
		
		_2_LED_blink(LED_CAR_PORT,LED_CAR_YELLOW,LED_walking_PORT,LED_walking_YELLOW,time_millis);
		LED_off(LED_CAR_PORT,LED_CAR_YELLOW);
		LED_off(LED_walking_PORT,LED_walking_YELLOW);
		LED_off(LED_walking_PORT,LED_walking_GREEN);
		
	
		interrupt=OFF;
		 Normal();break;
		
		case YELLOW:
			LED_on(LED_CAR_PORT,LED_CAR_GREEN);
			LED_on(LED_walking_PORT,LED_walking_RED);
			delay(time_millis);
			LED_off(LED_CAR_PORT,LED_CAR_GREEN);
			LED_off(LED_walking_PORT,LED_walking_RED);
			
			_2_LED_blink(LED_CAR_PORT,LED_CAR_YELLOW,LED_walking_PORT,LED_walking_YELLOW,time_millis);
			LED_off(LED_CAR_PORT,LED_CAR_YELLOW);
			LED_off(LED_walking_PORT,LED_walking_YELLOW);
			
			LED_on(LED_CAR_PORT,LED_CAR_RED);
			LED_on(LED_walking_PORT,LED_walking_GREEN);
			delay(time_millis);
			LED_off(LED_CAR_PORT,LED_CAR_RED);
			
			_2_LED_blink(LED_CAR_PORT,LED_CAR_YELLOW,LED_walking_PORT,LED_walking_YELLOW,time_millis);
			LED_off(LED_CAR_PORT,LED_CAR_YELLOW);
			LED_off(LED_walking_PORT,LED_walking_YELLOW);
			LED_off(LED_walking_PORT,LED_walking_GREEN);
			
		interrupt=OFF;
		Normal();
		break;
		
		case RED:
		LED_on(LED_CAR_PORT,LED_CAR_RED);
		LED_on(LED_walking_PORT,LED_walking_GREEN);
		delay(time_millis);
		
		LED_off(LED_CAR_PORT,LED_CAR_RED);
		
		
		_2_LED_blink(LED_CAR_PORT,LED_CAR_YELLOW,LED_walking_PORT,LED_walking_YELLOW,time_millis);
		LED_off(LED_CAR_PORT,LED_CAR_YELLOW);
		LED_off(LED_walking_PORT,LED_walking_YELLOW);
		LED_off(LED_walking_PORT,LED_walking_GREEN);
		
		interrupt=OFF;
		Normal();
		break;
		
		default:Normal();break;
	}
	
	
}


