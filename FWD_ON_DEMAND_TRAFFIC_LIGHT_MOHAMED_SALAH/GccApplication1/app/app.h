/*
 * app.h
 *
 * Created: 10/12/2022 8:42:50 PM
 *  Author: Mohamed Salah
 */ 


#ifndef APP_H_
#define APP_H_
#include "../MCAL/DIO/DIO_INTERFACE.h"
#include "../MCAL/Interrupt/interrupts.h"
#include "../MCAL/Timer/Timer.h"
#include "../ECUAL/Button/Button.h"
#include "../ECUAL/LED/LED.h"


#define  LED_CAR_PORT PORTA
#define  LED_CAR_GREEN 0
#define  LED_CAR_YELLOW 1
#define  LED_CAR_RED 2

#define	 LED_walking_PORT PORTB
#define  LED_walking_GREEN 0
#define  LED_walking_YELLOW 1
#define  LED_walking_RED 2

#define ON 1
#define OFF 0

typedef enum {RED,YELLOW,GREEN}car_signal_state;

static car_signal_state CAR_SIGNAL_STATE;
static uint32_t time_millis=5000;
static uint8_t interrupt;


void STOP(void);
void app_init(void);

void Normal(void);
void pedestrian(void);

void app_start(void);


#endif /* APP_H_ */