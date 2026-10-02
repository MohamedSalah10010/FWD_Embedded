/*
 * Button.h
 *
 * Created: 9/14/2022 10:27:26 PM
 *  Author: Mohamed Salah
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO/DIO_INTERFACE.h"


void Button_init(uint8_t buttonPort, uint8_t buttonPin);
uint8_t Button_read(uint8_t buttonPort, uint8_t buttonPin);


#endif /* BUTTON_H_ */