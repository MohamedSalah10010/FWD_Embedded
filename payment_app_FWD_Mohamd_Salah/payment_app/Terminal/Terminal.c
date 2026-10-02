#define _CRT_SECURE_NO_WARNINGS 1
#include "Terminal.h"
#include <time.h>
#include<stdio.h>


EN_terminalError_t getTransactionDate(ST_terminalData_t* termData)
{
	time_t currentTime;// it's a defined type in time.h
	time(&currentTime); // a function to get the real time thorugh my device
	
	struct tm* date= localtime(&currentTime); ; // in time.h they didn't typedef this struct that's why I used struct keyword, and date here contains a converted time type

	// to print the date in the DD/MM/YYYY format we use the following line noting that months in this librart starts from 0 and the years since 1900
	//printf("%i/%i/%i\n", date->tm_mday, date->tm_mon + 1, date->tm_year + 1900);
	
	sprintf(termData->transactionDate, "%02d/%02d/%04d", date->tm_mday, date->tm_mon + 1, date->tm_year + 1900);
	// The C library function int sprintf(char *str, const char *format, ...) sends formatted output to a string pointed to, by str. got from "https://www.tutorialspoint.com/c_standard_library/c_function_sprintf.htm"
	
	return TERMINAL_OK;
}

EN_terminalError_t isCardExpired(ST_cardData_t* cardData, ST_terminalData_t* termData)
{
	
	uint32_t transactionYears = (termData->transactionDate[8]-'0')*10 + (termData->transactionDate[9]-'0'); //seperate the transaction's years part

	uint32_t transactionMonths = (termData->transactionDate[3]-'0') * 10 + (termData->transactionDate[4]-'0'); //seperate the transaction's months part


	uint32_t cardYears = (cardData->cardExpirationDate[3]-'0') * 10 + (cardData->cardExpirationDate[4]-'0');//seperate the card's year part

	uint32_t cardMonths = (cardData->cardExpirationDate[0]-'0') * 10 + (cardData->cardExpirationDate[1]-'0');//seperate the card's months part

	//printf("test cardmonths: %d\ncardyears: %d\ntyears: %d\ntmonths: %d\n", cardMonths, cardYears, transactionYears, transactionMonths); // it was for testing while running

	if (transactionYears > cardYears)
	{
		return EXPIRED_CARD;
	}
	else if ((transactionMonths > cardMonths) && (transactionYears == cardYears)) {
		return EXPIRED_CARD;
	}
	else	
		return TERMINAL_OK;
}

EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData)
{
	printf("PLEASE ENTER THE AMOUNT OF THE TRANSACTION: ");
	scanf("%f", &(termData->transAmount)); // getting the amount of transaction from the user and send it to transamount in the termData struct

	if (termData->transAmount <= 0) // conditoining that the number isn't negative niether null
	{
		return INVALID_AMOUNT;
	}

	return TERMINAL_OK;
}

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData)
{
	if (termData->transAmount > termData->maxTransAmount) // check whether the max amount have been exceeded or not
	{
		printf("EXCEEDES THE MAXIMUM AMOUNT\n");
		return EXCEED_MAX_AMOUNT;
	}

	return TERMINAL_OK;
}

EN_terminalError_t setMaxAmount(ST_terminalData_t* termData, float max)
{
	/*float max; // initializing the max transaction amount
	puts("ENTER THE MAX AMOUNT FOR TRANSACTIONS: ");
	scanf("%f", &max);// get the max data from the user
	*/
	if (max <= 0)
	{
		return INVALID_MAX_AMOUNT;
		termData->maxTransAmount = 5000; // restore max to default amount 5000
	}
	
	termData->maxTransAmount = max;
	return TERMINAL_OK;
}