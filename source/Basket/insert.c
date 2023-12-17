#include "../../header/Basket.h"
#include "../../header/FileIO.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

node *top;
void insert(char *orderString){
  

    node *newNode; //This will create a new node
    newNode = (node *) malloc(sizeof(node)); //This allocates enough memory to store the node.
    newNode->order = malloc(strlen(orderString)+1); // This allocates enough memory to store the string in order
    strcpy(newNode->order, orderString); //This function copies what is in order string and
    newNode -> next = NULL;


    orderString = NULL;
    if (top == NULL){
        top = newNode;
    }
    else {
        node *current;
        current = (node*)malloc(sizeof(node));
        current = top;
         while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    iterate();

}


void iterate(){

    if (top == NULL){
        printf("The basket is empty\n");
    }
    else{
        printf("This is your basket:\n\n");
        sleep(1);
    node *temp = top; 
    while (temp != NULL) {
        printf("%s", temp->order);
        temp = temp->next;
    } 
    }

    sleep(1);
    printf("\n");
    afterBasket();


}

void afterBasket(){
     printf("1: add to order. 2: remove an item. 3: Pay\n");
    int *op = malloc(sizeof(int));
    scanf("%d",op);
    
    switch(*op){
    case 1:
       start();
        break;
    case 2:
       delete();
        break;
    case 3:
        printf("Please create a payment method\n");
        break;
    default:
        afterBasket();
        break;
    }
}


void delete(){


    if (top == NULL){
        printf("The basket is empty\n");
    }
    else{
        printf("This is your basket:\n\n");
        sleep(1);
    node *temp = top; 
    while (temp != NULL) {
        printf("%s", temp->order);
        temp = temp->next;
        }




    sleep(1);
   printf("Enter the item you want to delete (1,2,3,etc)\n");
   printf("You can only delete 1 item at a time\n");

    }


}