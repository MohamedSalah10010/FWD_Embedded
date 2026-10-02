/*
 * DIO_INTERFACE.h
 *
 * Created: 13/9/2022 8:36:51 PM
 *  Author: Mohamed Salah
 */
#include "Lib/BIT_MATH.h"
#include "Lib/STD_TYPES.h"
#include "DIO_REG.h"


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
 /********** configuration ************/
/*AVR PORTS*/

#define PORTA 'A'
#define PORTB 'B'
#define PORTC 'C'
#define	PORTD 'D'


/* AVR PIN number*/

#define PIN0	0
#define PIN1	1
#define PIN2	2
#define PIN3	3
#define PIN4	4
#define PIN5	5
#define PIN6	6
#define PIN7	7


/* AVR_INPUT_OUTPUT  */

#define INPUT 0
#define OUTPUT 1
#define HIGH 1
#define LOW 0
#define Connect  1
#define NotConnected 0
#define uint8_t_Direction_input		0x00
#define uint8_t_PinValue_LOW		0x00



#define Init_direction_default  uint8_t_Direction_input

#define Init_PinValue_default  uint8_t_PinValue_LOW

/*	FUNCTIONS	*/

void DIO_voidInit(void);
//******************************************* PORT **********************************

	/*uint8_t DIO_set_PORT_DIR(uint8_t portnum, uint8_t dir);

	uint8_t DIO_read_PORT(uint8_t portnum);

	uint8_t DIO_write_PORT(uint8_t portnum,uint8_t value);

	uint8_t DIO_toggle_PORT(uint8_t portnum);
*/
//******************************************** PIN **********************************

	uint8_t DIO_setPIN_DIR(uint8_t portnum, uint8_t pinnum, uint8_t dir);

	uint8_t DIO_read_PIN(uint8_t portnum,uint8_t pinnum);

	uint8_t DIO_write_PIN(uint8_t portnum,uint8_t pinnum,uint8_t value);

	uint8_t DIO_toggle_PIN(uint8_t portnum,uint8_t pinnum);




#endif /* DIO_INTERFACE_H_ */
