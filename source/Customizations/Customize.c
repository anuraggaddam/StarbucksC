#include <stdio.h>
#include <stdlib.h>
#include "../../header/Customize.h"
#include <string.h>
#include "../../header/FileIO.h"

char *customizations;
char *product;

void customize(char *item)
{
    // we are updating the global pointer product. This is where we keep the item of the product;
    // We will copy the item over. Then we will clear the item from memory. This way we can have a more unified system from here on out
    product = (char *)malloc(strlen(item) + 1);
    strcpy(product, item);

    // We are going to clear the memory and make it null
    free(item);
    item = NULL;

    size(); // we are going to call the size method before asking the user if they want to customize their order.
            // This way we can have the bare minimum down;

    // We are going to initialize the variable that gets user input;
    char *input;
    input = (char *)malloc(sizeof(char) * 5);
    printf("Would you like to customize your oder?\n");
    printf("y for yes n for no:\n");
    scanf("%s", input);
    input = (char *)realloc(input, sizeof(char));

    switch (input[0])
    {
    case 'y':
        free(input);
        input = NULL;
        options();
        break;
    case 'n':
        printf("You chose no\n");
        break;
    default:
        customize(product);
        break;
    }
}

void size()
{
    char *input;
    printf("Please choose a size\n");
    printf("S for small\nM for medium\nL for large\n");
    input = (char *)malloc(sizeof(char) * 5);
    scanf("%s", input);
    input = (char *)realloc(input, sizeof(char));

    switch (input[0])
    {
    case 's':
    case 'S':
        customizations = (char *)malloc(14);
        strcpy(customizations, "\tSize: small");
        free(input);
        input = NULL;
        break;
    case 'M':
    case 'm':
        customizations = (char *)malloc(14);
        strcpy(customizations, "\tSize: medium");
        free(input);
        input = NULL;
        break;
    case 'L':
    case 'l':
        customizations = (char *)malloc(14);
        strcpy(customizations, "\tSize: large");
        free(input);
        input = NULL;
        break;
    default:
        size();
        break;
    }
}



void options()
{
    char *File = (char *)malloc(strlen("../text/custoptions.txt") + 1);
    strcpy(File, "../text/custoptions.txt");
    customRead(File);
    printf("Press 0 for done");
     home(File);

    //After that, we will recursively as the user if they would like to add
    // more  to their order

}


