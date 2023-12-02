#include "../../header/Basket.h"
#include <std.io.h>
#include <stdlib.h>
#include <string.h>


void insert(char *orderString){
    node *newNode; //This will create a new node
    newNode = (node *) malloc(sizeof(node)); //This allocates enough memory to store the node.
    newNode-> order = malloc(strlen(orderString)); // This allocates enough memory to store the string in order
    strcpy(newNode->order, orderString); //This function copies what is in order string and
    newNode -> next = NULL;




}