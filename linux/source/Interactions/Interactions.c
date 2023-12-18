#include <stdio.h>
#include "../../header/FileIO.h"


//reusable cinput method. This method allows for unlimited picking
int input(){
    int choice;
    printf("\nPlease make a choice\n");
    scanf("%d", &choice);
    return choice;
}

// completed