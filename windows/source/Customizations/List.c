#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "..\\header\\Customize.h"
#include "..\\header\\FileIO.h"
#include "..\\header\\Basket.h"

tempcustomizationsList *head;
void tempInsert(char *addCustomization){
  tempcustomizationsList *newElement;
  newElement = malloc(sizeof(tempcustomizationsList));
  newElement->data = malloc(strlen(addCustomization) + 1);
  strcpy (newElement->data, addCustomization);
  newElement ->next = NULL;
  addCustomization = NULL;
  if (head == NULL){
    head = newElement;

  }else {
        tempcustomizationsList *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newElement;
    }


}

void tempIterate(){
    if (head == NULL){
    printf("Sorry, There is no list");

  }else {
        tempcustomizationsList *current = head;
        while (current->next != NULL) {
          printf("%s",current->data);
            current = current->next;
        }

    }
}


void check(char *item, char *number) {

  int toTheEnd = 0;

 char *addCusto = (char*)malloc(strlen (item)*3);
   addCusto[0] = '\0';
     strcat(addCusto, "\t\t");
    strcat(addCusto, item);
    strcat(addCusto, "'s packets: ");
    strcat(addCusto,number);
    strcat(addCusto,"\n");



    tempcustomizationsList *newNode = malloc(sizeof(tempcustomizationsList));
    newNode->data = malloc(strlen(addCusto)+1);
    strcpy(newNode->data, addCusto);
    newNode->next = NULL;    



  tempcustomizationsList *current = head;
  tempcustomizationsList * prev = malloc(sizeof(tempcustomizationsList));
  prev = NULL;
        while (current != NULL) {
        if (strstr(current->data, item) != NULL) {
            prev -> next = newNode;
            newNode->next = current->next;
            toTheEnd = 1;
            break;
        }
        prev = current;
        current = current->next;
    }
  

    if(toTheEnd == 0){
      tempInsert(addCusto);
    }


}

void clear(){
  head = NULL;
}



void clean (){

  tempcustomizationsList *iterator = head;
  tempcustomizationsList *prev = NULL;
  while(iterator!=NULL){
    if(strstr(iterator->data,": 0")){
     prev->next = iterator->next;
    }
    prev = iterator;
    iterator = iterator->next;
  }

  ship();

}

void ship() {
    tempcustomizationsList* finalit = head;
    char* finalCustomize = calloc(1,sizeof(char)*100);

    char uniqueEntries[100] = "";

    while (finalit != NULL) {
        if (strstr(uniqueEntries, finalit->data) == NULL) {
            strcat(finalCustomize, finalit->data);
            strcat(uniqueEntries, finalit->data);
        }
        finalit = finalit->next;
    }

   insert(finalCustomize);
   clear();
   
    free(finalCustomize);
    finalCustomize = NULL;
    head = NULL;
    sleep(1);

    printf("added to cart\n");
   start();

}


