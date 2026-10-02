/*
 * LED.h
 *
 * Created: 9/14/2022 10:01:12 PM
 *  Author: Mohamed Salah
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO/DIO_INTERFACE.h"
#include "../../MCAL/Timer/Timer.h"

void LED_init(uint8_t ledPort, uint8_t ledPin);

void LED_on(uint8_t ledPort, uint8_t ledPin);
void LED_off(uint8_t ledPort, uint8_t ledPin);
void LED_toggle(uint8_t ledPort, uint8_t ledPin);
void LED_blink(uint8_t led_Port, uint8_t led_Pin, uint32_t delay_millis);
void _2_LED_blink(uint8_t ledPort_1, uint8_t ledPin_1,uint8_t ledPort_2, uint8_t ledPin_2,uint32_t delay_millis);

#endif /* LED_H_ */