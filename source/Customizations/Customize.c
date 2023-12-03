#include <stdio.h>
#include <stdlib.h>
#include "../../header/Customize.h"
#include <string.h>

void customize(char *item){

    //We are going to initialize the variable that gets user input;
    char *input;
    input = (char *) malloc(sizeof (char)*5);

    printf("\nYou have chosen:\n%s\n", item);
    printf("Would you like to customize your oder?\n");
    printf("y for yes n for no:\n");
    scanf("%s",input);
    input = (char*) realloc(input, sizeof (char));

    switch (input[0]) {
        case 'y':
            printf("You chose Yes\n");
            break;

        case 'n':
            printf("You chose no\n");
            break;

        default:
            customize(item);
            break;
    }

}