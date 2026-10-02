
#include "Server.h"


ST_accountsDB_t* Refrence = 0;
sequance = 1;

/*DATA BASE*/
    ST_accountsDB_t accounts_DB[MAXSIZE] = {
        {15000.0,RUNNING, "8989374615436851"},
        {2000.0,RUNNING ,"4197623105690241"},
        {100000.0, RUNNING,"5807007076043875"},
        {3000.0, BLOCKED,"5258315796301478"},
        {67000.0, BLOCKED,"5117873155096031"},
        {12000.0, RUNNING, "7885974615436851"},
        {25500.0,RUNNING ,"5297621305690241"},
        {120000.0, RUNNING,"5808007076043875"},
        {6000.0, BLOCKED,"5258315758231478"},
        {98000.0, BLOCKED,"6283873155096031"}


    }; // data base for testing sake

    
    ST_transaction_t transDB[MAXSIZE] = {{{0}}};/* If the first member of your struct happens to
    be another struct object, whose first member has scalar type, then you'll have to use {{{0}}} 
    got from "https://stackoverflow.com/questions/5434865/quickest-way-to-initialize-an-array-of-structures-to-all-0s"*/
    /*transction initilizing function 
    -not working well because Exception thrown at 0x00007FFBB57CD215 (ucrtbased.dll) 
    in payment_app.exe: 0xC0000005: Access violation writing location 0x000000AAEDF0002D. -*/
  /*void init_TransactionDB(ST_transaction_t* transDB) {
      uint16_t x = 0;
      for (uint32_t i = 0; i < MAXSIZE; i++)
      {
          strcpy(transDB[i].cardHolderData.cardExpirationDate, "00/00");
         strcpy(&transDB[i].cardHolderData.cardHolderName, "");
          strcpy(transDB[i].cardHolderData.primaryAccountNumber , "");
         strcpy(transDB[i].terminalData.transactionDate , "00/00/0000");
         transDB[i].terminalData.transAmount = 0;
          transDB[i].transState = APPROVED;
          transDB[i].transactionSequenceNumber = 0;
      }*/

    
     /*FUNCTION IMPLEMENTAION */

    

     EN_serverError_t isValidAccount(ST_cardData_t* cardData, ST_accountsDB_t* accountRefrence) {
 
         
         while (getCardHolderName(cardData) == WRONG_NAME) // while loop to get the card holder name
         {
              getCardHolderName(cardData);
         }
         while (getCardExpiryDate(cardData) == WRONG_EXP_DATE)// while loop to get the card expiry date
         {
             getCardExpiryDate(cardData);
         }
         while (getCardPAN(cardData) == WRONG_PAN)// while loop to get the card PAN
         {
             getCardPAN(cardData);
         }
         while (getTransactionAmount(cardData) == INVALID_AMOUNT)// while loop to get the card PAN
         {
             getTransactionAmount(cardData);
         }
         /*if all the info is correct it will initilazing a linear search via accounts data base*/
         
             uint16_t i = 0;
             for (i = 0; i < MAXSIZE; i++) // for loop to ckeck if the card is in the data base or not
             {
                 if (strcmp(cardData->primaryAccountNumber, accounts_DB[i].primaryAccountNumber) == 0)
                 {
                      Refrence = & accounts_DB[i];// pointing to the specfied account_DB for other calls
                     
                     return SERVER_OK;
                 }
             }
  
         
        return ACCOUNT_NOT_FOUND;// stolen card

         }
 
     EN_serverError_t isBlockedAccount(ST_accountsDB_t* accountRefrence) {

             if (Refrence->state == BLOCKED) {
                 return BLOCKED_ACCOUNT;
             }
              return SERVER_OK;
 
     }

     EN_serverError_t isAmountAvailable(ST_terminalData_t* termData) {
         
         getTransactionAmount(termData);
        
      /*checking if the account has suffiecent balance for the transaction */
     if ((termData->transAmount) > (Refrence->balance)) {
             return LOW_BALANCE;
     }
     
            return SERVER_OK;
     
 
     }


     EN_serverError_t saveTransaction(ST_transaction_t* transData) {
         
         uint16_t c = sequance - 1;// beacuse sequance is initially 1 not 0
         /*set the transaction sequance*/
       
     
         /*storing the transaction data*/
         if (c != MAXSIZE) {
             /*settoing card holderdata in the transaction database*/
             strcpy(transDB[c].cardHolderData.cardExpirationDate, transData->cardHolderData.cardExpirationDate);
             strcpy(transDB[c].cardHolderData.cardHolderName, transData->cardHolderData.cardHolderName);
             strcpy(transDB[c].cardHolderData.primaryAccountNumber, transData->cardHolderData.primaryAccountNumber);
         
             /*settoing terminal data in the transaction database*/
             strcpy(transDB[c].terminalData.transactionDate, transData->terminalData.transactionDate);
             transDB[c].terminalData.maxTransAmount = transData->terminalData.maxTransAmount;
             transDB[c].terminalData.transAmount = transData->terminalData.transAmount;
         
             /*setting trasnsaction sequance number*/
             transDB[c].transactionSequenceNumber = transData->transactionSequenceNumber;
         
             /*setting trasnsaction state number*/
             transDB[c].transState = transData->transState;
         
             /*increments for other savings*/
             sequance++;
             
             return SERVER_OK;
             
         }
         return SAVING_FAILED;
         
     }

     EN_serverError_t getTransaction(uint32_t transactionSequenceNumber, ST_transaction_t* transData) {

         uint32_t c = transactionSequenceNumber - 1;// because the counter aka transactionSequenceNumber starts from 1 thus its index is (transactionSequenceNumber-1)

         transData->transactionSequenceNumber = transactionSequenceNumber;
         /*to check if this transtion data has the same transaction sequance*/
         if (transData[c].transactionSequenceNumber == transactionSequenceNumber)
         {
             /*printig the transtion data of the specified transaction*/

             printf("\n**********************TRANSACTION %d****************\n", transactionSequenceNumber);

             printf("Card Holder Name :\t%s\n", transData[c].cardHolderData.cardHolderName);
             printf("Card PAN :\t%s\n", transData[c].cardHolderData.primaryAccountNumber);
             printf("Card Expiration Date :\t%s\n", transData[c].cardHolderData.cardExpirationDate);

             printf("Transaction Date :\t%s\n", transData[c].terminalData.transactionDate);
             printf("Transaction Amount :\t%f\n", transData[c].terminalData.transAmount);
             printf("Transaction Maximum Amount :\t%f\n", transData[c].terminalData.maxTransAmount);

             printf("Transaction State :\t%d\n", transData[c].transState);
             printf("account balance :\t%f\n", Refrence->balance);

             return SERVER_OK;
         }
         puts("TRANSACTION_NOT_FOUND"); 
         return TRANSACTION_NOT_FOUND;


     }


     


     EN_transState_t recieveTransactionData(ST_transaction_t* transData) {

         /*Calling all of the other functions*/

          if (isValidAccount(&(transData)->cardHolderData, Refrence) == ACCOUNT_NOT_FOUND)
         {
             puts("DECLINED_FRAUD_CARD");
             transData->transState = FRAUD_CARD;
             transData->terminalData.transAmount = 0;
             return FRAUD_CARD;
         }
         else if (isBlockedAccount(Refrence) == BLOCKED_ACCOUNT)
         {
             puts("DECLINED_STOLEN_CARD");
             transData->transState = DECLINED_STOLEN_CARD;
             transData->terminalData.transAmount = 0;
             return DECLINED_STOLEN_CARD;
         }
         else if (isAmountAvailable(&(transData->terminalData)) == LOW_BALANCE)
         {
             puts("DECLINED_INSUFFECIENT_FUND");
             transData->transState = DECLINED_INSUFFECIENT_FUND;
             transData->terminalData.transAmount = 0;
             return DECLINED_INSUFFECIENT_FUND;
         }
         else if (isBelowMaxAmount(&(transData->terminalData)) == EXCEED_MAX_AMOUNT)
         {
             puts("DECLINED_EXCEED_MAX_AMOUNT");
             transData->terminalData.transAmount = 0;
             transData->transState = DECLINED_INSUFFECIENT_FUND;
             return DECLINED_INSUFFECIENT_FUND;
         }
         else if (saveTransaction(transData) == SAVING_FAILED)
         {
             puts("TRANSACTION_NOT_SAVED");
             transData->transState = INTERNAL_SERVER_ERROR;
             transData->terminalData.transAmount = 0;
             return INTERNAL_SERVER_ERROR;
         }
         else if (isCardExpired(&transData->cardHolderData, &transData->terminalData) == EXPIRED_CARD)
         {
             puts("EXPIRED_CARD");
             transData->transState = FRAUD_CARD;
             transData->terminalData.transAmount = 0;
             return FRAUD_CARD;
         }
         else
         {
             (Refrence->balance) -= (transData->terminalData.transAmount);// substracting the transaction amount from the balance

             puts("APPROVED_TRANSACTION");
             transData->transState = APPROVED;
             return APPROVED;
         }

     }
