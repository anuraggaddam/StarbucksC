#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../header/Customize.h"
#include "../../header/Basket.h"

tempcustomizationsList *head;
void tempInsert(char *addCustomization){
  tempcustomizationsList *newElement;
  newElement = malloc(sizeof(tempcustomizationsList));
  newElement->data = malloc(strlen(addCustomization) + 1);
  strcpy (newElement->data, addCustomization);
  newElement ->next = NULL;
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

  //This variable will always = 0. If it equals =0, we call temp insert. If not, we will skip over the code.
  int toTheEnd = 0;


//This is to convert a option to a String. 
 char *addCusto = (char*)malloc(strlen (item)*3);
   addCusto[0] = '\0';
     strcat(addCusto, "\t");
    strcat(addCusto, item);
    strcat(addCusto, "'s packets: ");
    strcat(addCusto,number);
    strcat(addCusto,"\n");



    tempcustomizationsList *newNode = malloc(sizeof(tempcustomizationsList));
    newNode->data = malloc(strlen(addCusto)+1);
    strcpy(newNode->data, addCusto);
    newNode->next = NULL;    



  //This section is here to detect weather or not an item is already been customized. 
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

    // Use a separate string to keep track of unique entries
    char uniqueEntries[100] = "";

    while (finalit != NULL) {
        if (strstr(uniqueEntries, finalit->data) == NULL) {
            strcat(finalCustomize, finalit->data);
            strcat(uniqueEntries, finalit->data);
        }
        finalit = finalit->next;
    }

   insert(finalCustomize);

    free(finalCustomize);
    finalCustomize = NULL;
}


