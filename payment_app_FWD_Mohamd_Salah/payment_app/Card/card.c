#define _CRT_SECURE_NO_WARNINGS 1
/****Function implemntations****/

#include "card.h"
#include <string.h>
#include <stdio.h>



EN_cardError_t getCardHolderName(ST_cardData_t* cardData) {

	char name[100] = { '\0' };
	
	puts("PLEASE ENTER CARD HOLDER NAME: ");
	gets(name); // getting holder name from the user 
	
	/*handling errors*/
	if ((name[0] == '\0')
		|| strlen(name) < 20 
		|| strlen(name) > 24) // check if the name is empty or less than 20 characters or greater than 24 -invalid inputs-
	{
		return WRONG_NAME;
	}

	strcpy(cardData->cardHolderName,name); // setting the holder name in the cardDATA structure
	cardData->cardHolderName[24] = '\0'; // providing the null char to the end of the array, so it truns into string
	
	return CARD_OK;
}

EN_cardError_t getCardExpiryDate(ST_cardData_t * cardData)
	{
		printf("PLEASE ENTER THE CARD EXPIARY DATE AS (MM/YY) : ");
		
		gets(cardData->cardExpirationDate);// getting the card expiary date from the user 
		

		if(
			(cardData->cardExpirationDate[0] == '\0') // checking if null
			|| (strlen(cardData->cardExpirationDate) != 5) // checking if the entry is not as  the specified format
			|| (cardData->cardExpirationDate[2] != 47) // checking if the 3rd char. is "/" or not
			|| ((cardData->cardExpirationDate[0] + cardData->cardExpirationDate[1]) < 97) // checking the month digits that if its in the range of numbers or not in ascii representation '0'+'1'=48+49=97 --> min range 
			|| ((cardData->cardExpirationDate[0] + cardData->cardExpirationDate[1]) > 105)// checking the month digits that if its in the range of numbers or not in ascii representation '0' + '9' = 48 + 57 = 105 --> max range
			)
		{
			return WRONG_EXP_DATE;
		}
		
		return CARD_OK;
	}

EN_cardError_t getCardPAN(ST_cardData_t* cardData)
{
	printf("PLEASE ENTRE THE PAN NUMBER: ");
	gets(cardData->primaryAccountNumber); //  getting the card PAN  from the user


	if ((cardData->primaryAccountNumber[0] == '\0')// check if the PAN is empty or less than 16 characters or greater than 19 - invalid inputs -
		|| (strlen(cardData->primaryAccountNumber) < 16)
		|| (strlen(cardData->primaryAccountNumber) > 19))
	{
		return WRONG_PAN;
	}
	return CARD_OK;
}




