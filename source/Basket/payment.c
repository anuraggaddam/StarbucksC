#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "../../header/Basket.h"
#include "../../header/FileIO.h"


void count(node *orderNode){
	int small = 0;
	int medium = 0;
	int large = 0;
	int *pSmall = &small;
	node *cur = orderNode;

	if (orderNode == NULL){
		printf("Cart empty. Returning to menu...");
		start();
	}
	while(cur != NULL){
		if ( strstr(cur->order, "large") != NULL){
			large++;
		}
		if ( strstr(cur->order, "small") != NULL){
			small++;
		}
		if ( strstr(cur->order, "medium") != NULL){
			large++;
		}
		cur = cur->next;
	}

    calculate(&small, &medium, &large, orderNode);
}


void calculate(int *s, int *m, int *l , node *orderNode){
	int total = (5* (*l)) + (4* (*l)) + (3* (*s));
	int *pTotal = &total;
	printf ("You ordered: %d of small drinks\n",*s);
	printf ("You ordered: %d of medium drinks\n",*m);
	printf ("You ordered: %d of large drinks\n",*l);
	printf("Your total is: $%d\n",total);

	info(pTotal, orderNode);

}

void info(int *total, node *orderNode){
	   char first[100];
	   char last[100];
	   char full[100];
	   char money[20];
	     sprintf(money, "%d", *total);
	     

    printf("Enter your first name: ");
   	scanf("%s",first);
   	printf("Enter your last name: ");
   	scanf("%s",last);

    strcat(full,first);
    strcat(full," ");
    strcat(full,last);
   

   //find the location
    printf("Pick your location:\n");
    printf("1. Seattle\n");
    printf("2. Bellevue\n");
    printf("3. Bothell\n");
    printf("4. Bellingham\n");

    int location;
    char building[30];
    printf("Enter: ");
   	scanf("%d", &location);

   	switch (location){
   	case 1:
   		strcpy(building,"Seattle");
   		break;
   	case 2:
   		strcpy(building,"Bellevue");
   		break;
   	case 3:
   		strcpy(building,"Bothell");
   		break;
   	case 4:
   		strcpy(building,"Bellingham");
   		break;
   	default:
   		info(total, orderNode);
   		break;
   	}

   	char date[20];
   	char receipt[1000];
   	char time[20];
   	int cardtype;
   	char card[16];
   	int cardnumber;
   	int three;

   	printf("\nPlease enter date in this format: MM/DD/YY -> ");
   	scanf("%s",&date);

   	printf("\nPlease enter a time in this format: HH:MM -> ");
   	scanf("%s",&time);


   	printf("\nPayment system loading:\n");
   	printf("Enter 1 for Visa 2 for MasterCard: ");
   	scanf("%d", &cardtype);

   	switch(cardtype){
   	case 1:
   		strcpy(card, "Visa");
   		break;
   	case 2:
   		strcpy(card, "MasterCard");
   		break;
   	default:
   		info(total, orderNode);
   		break;
   	}

   	printf("Please enter card number\n");
   	scanf("%d", &cardnumber);
   	printf("\nPlease enter 3 digits: ");
   	scanf("%d",&three);



   	strcat(receipt, full);
   	strcat(receipt,"\n");

   	node *iterater = orderNode;

   	while(iterater != NULL){
   		strcat(receipt,iterater->order);
   		strcat(receipt, "\0");
   		iterater = iterater->next;
   	}
   	strcat(receipt, "\t\t\t\tTotal: $");
   	strcat(receipt, money);
   	strcat(receipt, "\nPickup: ");
   	strcat(receipt, date);
   	strcat(receipt, " ");
   	strcat(receipt, time);
   	strcat(receipt, " @");
   	strcat(receipt, building);
   	strcat(receipt,"\n");
   	strcat(receipt, "Paid ");
   	strcat(receipt, card);
   	strcat(receipt,"\n");



 	//this part ain't working


	char filename[] = "../receipts/";
	strcat(filename, full);
	strcat(filename, " ");
	strcat(filename, building);
	strcat(filename, ".txt");
	printf("Successfully placed order");

	 FILE *file;
	file = fopen(filename, "w");
	fprintf(file, "%s", receipt);

	fclose(file);
}