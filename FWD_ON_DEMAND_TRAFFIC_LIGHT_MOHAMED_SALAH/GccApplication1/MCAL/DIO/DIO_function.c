/*
 * DIO_program.c
 *
 * Created: 13/9/2022 8:50:05 PM
 *  Author: Mohamed Salah
 */

#include "DIO_INTERFACE.h"
#include "DIO_REG.h"


 /*void DIO_voidInit(void)
 {
		DDRA_REG=Init_direction_default;
		DDRB_REG=Init_direction_default;
		DDRC_REG=Init_direction_default;
		DDRD_REG=Init_direction_default;

		PINA_REG=Init_PinValue_default;
		PINB_REG=Init_PinValue_default;
		PINC_REG=Init_PinValue_default;
		PIND_REG=Init_PinValue_default;
 }*/

 /************	PORT FUNCTIONS	**********/
/*	 uint8_t DIO_set_PORT_DIR(uint8_t portnum, uint8_t dir){

	 uint8_t Local_uint8_tErrorState = STD_TYPES_OK;

	 if(((portnum==PORTA)||(portnum==PORTB)||(portnum==PORTC)||(portnum==PORTD)) && ((dir==INPUT)||(dir==OUTPUT)))
 {
	 switch (portnum)
	  {
			case PORTA: 
			for(int i=0;i<=7;i++){
			if (dir==OUTPUT){SET_BIT(DDRA_REG,i);}
			else {CLR_BIT(DDRA_REG,i);}
			}
			break;
			case PORTB:for(int i=0;i<=7;i++){
				if (dir==OUTPUT){SET_BIT(DDRB_REG,i);}
				else {CLR_BIT(DDRB_REG,i);}
			}
			break;
			case PORTC:for(int i=0;i<=7;i++){
				if (dir==OUTPUT){SET_BIT(DDRC_REG,i);}
				else {CLR_BIT(DDRC_REG,i);}
			}
			break;
			case PORTD: for(int i=0;i<=7;i++){
				if (dir==OUTPUT){SET_BIT(DDRD_REG,i);}
				else {CLR_BIT(DDRD_REG,i);}
			}
			break;
			default:Local_uint8_tErrorState = STD_TYPES_NOK;break;

		}

 }
	 else
	  Local_uint8_tErrorState = STD_TYPES_NOK;
	 return Local_uint8_tErrorState;
	 }


	 uint8_t DIO_read_PORT(uint8_t portnum)
	 {
		 uint8_t Local_uint8_tErrorState = STD_TYPES_OK;
        volatile uint8_t value=0;
		 if((portnum==PORTA)||(portnum==PORTB)||(portnum==PORTC)||(portnum==PORTD))
		 {

			switch(portnum)
			{
			case PORTA: value=PINA_REG;break;
			case PORTB: value=PINB_REG;break;
			case PORTC: value=PINC_REG;break;
			case PORTD: value=PIND_REG;break;
			default: Local_uint8_tErrorState = STD_TYPES_NOK;break;
			}

		 }
		 else
		  Local_uint8_tErrorState = STD_TYPES_NOK;
		 return value;

	 }


	 uint8_t DIO_write_PORT(uint8_t portnum,uint8_t value)
	 {
	uint8_t Local_uint8_tErrorState = STD_TYPES_OK;

	if(((portnum==PORTA)||(portnum==PORTB)||(portnum==PORTC)||(portnum==PORTD))&&((value==HIGH)||(value==LOW)))
	{

		switch(portnum)
		{
			case PORTA: PORTA_REG=value;break;
			case PORTB: PORTB_REG=value;break;
			case PORTC: PORTC_REG=value;break;
			case PORTD: PORTD_REG=value;break;
			default: Local_uint8_tErrorState = STD_TYPES_NOK;break;
		}

	}
	else{
	 Local_uint8_tErrorState = STD_TYPES_NOK;}

	return Local_uint8_tErrorState;

	 }

	 uint8_t DIO_toggle_PORT(uint8_t portnum)
	 {
		 uint8_t Local_uint8_tErrorState = STD_TYPES_OK;

		 if((portnum==PORTA)||(portnum==PORTB)||(portnum==PORTC)||(portnum==PORTD))
		 {
			 switch(portnum)
			 {
				 case PORTA: PORTA_REG=~PORTA_REG;break;
				 case PORTB: PORTB_REG=~PORTB_REG;break;
				 case PORTC: PORTC_REG=~PORTC_REG;break;
				 case PORTD: PORTD_REG=~PORTD_REG;break;
				 default: Local_uint8_tErrorState = STD_TYPES_NOK;break;
			 }

		 }
		 else
		  Local_uint8_tErrorState = STD_TYPES_NOK;
		 return Local_uint8_tErrorState;
	 }
*/

	 /************ PIN FUNCTIONS ************/
	uint8_t DIO_setPIN_DIR(uint8_t portnum, uint8_t pinnum, uint8_t dir)
	{
		uint8_t Local_uint8_tErrorState = STD_TYPES_OK;

		if (((portnum==PORTA)||(portnum==PORTB)||(portnum==PORTC)||(portnum==PORTD))&& (pinnum<=PIN7)&&((dir==INPUT)||(dir==OUTPUT)))
		{
			switch(portnum)
			{
			case PORTA:
			if (dir==OUTPUT){ SET_BIT(DDRA_REG,pinnum);}
			else {CLR_BIT(DDRA_REG,pinnum);}
			break;

			case PORTB:
			if (dir==OUTPUT){ SET_BIT(DDRB_REG,pinnum);}
			else {CLR_BIT(DDRB_REG,pinnum);}
			break;

			case PORTC:
			if (dir==OUTPUT){ SET_BIT(DDRC_REG,pinnum);}
			else {CLR_BIT(DDRC_REG,pinnum);}
			break;

			case PORTD:
			if (dir==OUTPUT){ SET_BIT(DDRD_REG,pinnum);}
			else {CLR_BIT(DDRD_REG,pinnum);}
			break;

			default: Local_uint8_tErrorState = STD_TYPES_NOK;break;
			}

		}
		else
		 Local_uint8_tErrorState = STD_TYPES_NOK;
		return Local_uint8_tErrorState;
			}

	uint8_t DIO_read_PIN(uint8_t portnum,uint8_t pinnum)
	{
		uint8_t Local_uint8_tErrorState = STD_TYPES_OK;
        volatile uint8_t value=0;
		if (((portnum==PORTA)||(portnum==PORTB)||(portnum==PORTC)||(portnum==PORTD))&& (pinnum<=PIN7))
		{


			switch(portnum)
			{
				case PORTA:	value= READ_BIT(PINA_REG,pinnum);
				break;

				case PORTB:	value= READ_BIT(PINB_REG,pinnum);
				break;

				case PORTC:	value= READ_BIT(PINC_REG,pinnum);
				break;

				case PORTD:	value= READ_BIT(PIND_REG,pinnum);
				break;

				default: Local_uint8_tErrorState = STD_TYPES_NOK;break;
			}

		}
		else
		 Local_uint8_tErrorState = STD_TYPES_NOK;
		return value;
	}


	uint8_t DIO_write_PIN(uint8_t portnum,uint8_t pinnum,uint8_t value)
	{
		uint8_t Local_uint8_tErrorState = STD_TYPES_OK;

		if (((portnum==PORTA)||(portnum==PORTB)||(portnum==PORTC)||(portnum==PORTD))&& (pinnum<=PIN7)&&((value==HIGH)||(value==LOW)))
		{
			switch(portnum)
			{
				case PORTA:
				if (value==HIGH){ SET_BIT(PORTA_REG,pinnum);}
				else {CLR_BIT(PORTA_REG,pinnum);}
				break;

				case PORTB:
				if (value==HIGH){ SET_BIT(PORTB_REG,pinnum);}
				else {CLR_BIT(PORTB_REG,pinnum);}
				break;

				case PORTC:
				if (value==HIGH){ SET_BIT(PORTC_REG,pinnum);}
				else {CLR_BIT(PORTC_REG,pinnum);}
				break;

				case PORTD:
				if (value==HIGH){ SET_BIT(PORTD_REG,pinnum);}
				else {CLR_BIT(PORTD_REG,pinnum);}
				break;

				default: Local_uint8_tErrorState = STD_TYPES_NOK;break;
			}

		}
		else
		 Local_uint8_tErrorState = STD_TYPES_NOK;
		return Local_uint8_tErrorState;
	}

	uint8_t DIO_toggle_PIN(uint8_t portnum,uint8_t pinnum)
	{
		uint8_t Local_uint8_tErrorState = STD_TYPES_OK;

		if (((portnum==PORTA)||(portnum==PORTB)||(portnum==PORTC)||(portnum==PORTD))&& (pinnum<=PIN7))
		{

			switch(portnum)
			{
				case PORTA:	 TOGGLE_BIT(PORTA_REG,pinnum);
				break;

				case PORTB:	 TOGGLE_BIT(PORTB_REG,pinnum);
				break;

				case PORTC:	 TOGGLE_BIT(PORTC_REG,pinnum);
				break;

				case PORTD:	 TOGGLE_BIT(PORTD_REG,pinnum);
				break;

				default: Local_uint8_tErrorState = STD_TYPES_NOK;break;
			}

		}
		else
		 Local_uint8_tErrorState = STD_TYPES_NOK;
		return Local_uint8_tErrorState;
	}


	
