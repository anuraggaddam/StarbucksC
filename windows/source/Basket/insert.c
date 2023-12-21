#include "..\\..\\header\\Basket.h"
#include "..\\..\\header\\FileIO.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

node *top;
void insert(char *orderString){
  

    node *newNode;
    newNode = (node *) malloc(sizeof(node)); 
    newNode->order = malloc(strlen(orderString)+1); 
    strcpy(newNode->order, orderString); 
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
        count(top);
        break;
    default:
        afterBasket();
        break;
    }
}


void delete() {
    if (top == NULL) {
        printf("The basket is empty\n");
    } else {
        int size = checkSize();
        int option;
       
        sleep(1);
        printf("Enter the item you want to delete (1, 2, 3, etc)\n");
        printf("You can only delete 1 item at a time\n");
        printf("Enter number:\n");
        scanf("%d",&option);

        if (option >size){
            delete();
        }
        else if(option == 1 && size == 1){
            top = NULL;
        }else if(option == 1){
            node *prev = top;
            node *current = prev->next;
            top = current;
        }else{
            node *current = top;
            node *prev;
            for (int a = 1; a < option; a ++){
                prev = current;
                current = current->next;
            }
            prev->next = current->next;
        current = NULL;
        prev = NULL;
        }

        start();

    }
}

int checkSize() {
    int count = 0;
    if (top == NULL) {
        return 0;
    } else {
        node* temp = top; 
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
    }

    return count;
}




