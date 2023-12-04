#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../header/Customize.h"


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
          printf("%s",current->data);

    }
}
