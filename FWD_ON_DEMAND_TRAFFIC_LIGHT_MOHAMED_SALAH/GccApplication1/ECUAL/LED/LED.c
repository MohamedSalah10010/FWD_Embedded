/*
 * LED.c
 *
 * Created: 9/14/2022 10:00:58 PM
 *  Author: Mohamed Salah
 */ 

#include "LED.h"

void LED_init(uint8_t ledPort, uint8_t ledPin)
{
	
	DIO_setPIN_DIR(ledPort,ledPin,OUTPUT);
}
void LED_on(uint8_t ledPort, uint8_t ledPin)
{
	
	DIO_write_PIN(ledPort,ledPin,HIGH);
	
}
void LED_off(uint8_t ledPort, uint8_t ledPin)
{
	
	DIO_write_PIN(ledPort,ledPin,LOW);
}

void LED_toggle(uint8_t ledPort, uint8_t ledPin)
{
	DIO_toggle_PIN(ledPort,ledPin);
	
}

void LED_blink(uint8_t ledPort, uint8_t ledPin,uint32_t delay_millis){
uint32_t max= (delay_millis)/400; 
uint32_t N_blinks=0;
while(N_blinks<max){	
	LED_toggle(ledPort,ledPin);
	delay(200);
	LED_toggle(ledPort,ledPin);
	delay(200);
	N_blinks++;
}
}

void _2_LED_blink(uint8_t ledPort_1, uint8_t ledPin_1,uint8_t ledPort_2, uint8_t ledPin_2,uint32_t delay_millis)
{
		uint32_t max= (delay_millis)/400; 
		uint32_t N_blinks=0;
		while(N_blinks<max){
			LED_toggle(ledPort_1,ledPin_1);
			LED_toggle(ledPort_2,ledPin_2);
			delay(200);
			LED_toggle(ledPort_1,ledPin_1);
			LED_toggle(ledPort_2,ledPin_2);
			delay(200);
			N_blinks++;
		}
	}


