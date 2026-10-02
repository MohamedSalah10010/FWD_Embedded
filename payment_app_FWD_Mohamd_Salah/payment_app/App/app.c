
#include "app.h"
#include "..\Card\card.h"
#include "..\Terminal\terminal.h"
#include "..\Server\server.h"

#include <stdio.h>
#include <string.h>

void appStart(void)
{
	ST_transaction_t transaction;
	ST_transaction_t* transactionptr = &transaction;

	
	setMaxAmount(&(transactionptr->terminalData), 5000);
	
	uint8_t anotherTransProcess='y', anotherTransDetails;
	

	do
	{
		getTransactionDate(&(transactionptr->terminalData));// calling the getTransactionDate to get the current time

		recieveTransactionData(transactionptr); // calling the recieveTransactionData to start the server
		
		printf("\n\nDo you want another transaction?\n(y/n): ");
		scanf(" %c", &anotherTransProcess);

	} while (anotherTransProcess == 'y');
	
	/*check if the user want to see specific transaction details*/

	printf("Do you want to show specific transaction details? (y/n) : ");
	scanf(" %c", &anotherTransDetails);
	if (anotherTransDetails == 'y')
	{
		uint32_t num;
		printf("Enter the sequence of the transaction: ");
		scanf("%d", &num);

		getTransaction(num, &transaction);


	}
}

int main() {

	appStart();
}