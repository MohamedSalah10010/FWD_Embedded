/*
 * CFile1.c
 *
 * Created: 9/14/2022 10:27:01 PM
 *  Author: Mohamed Salah
 */ 

#include "Button.h"



void Button_init(uint8_t buttonPort, uint8_t buttonPin)
{
	
	DIO_setPIN_DIR(buttonPort,buttonPin,INPUT);
}
uint8_t Button_read(uint8_t buttonPort, uint8_t buttonPin)
{
	return DIO_read_PIN(buttonPort,buttonPin);
}
