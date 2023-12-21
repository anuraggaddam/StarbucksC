#include <stdio.h>
#include <stdlib.h>
#include "..\\..\\header\\Customize.h"
#include <string.h>
#include "..\\..\\header\\FileIO.h"

char *customizations;
char *product;


void customize(char *item)
{
    product = (char *)malloc(strlen(item) + 1);
    strcpy(product, item);
    free(item);
    item = NULL;

    size(); 

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
     clean();
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
    case 'S':
    case 's':
        customizations = (char *)malloc(14);
        strcpy(customizations, "\n\t\tSize: small\n");
        tempInsert (customizations);
        free(input);
        free (customizations);
        input = NULL;
        break;
    case 'M':
    case 'm':
        customizations = (char *)malloc(14);
        strcpy(customizations, "\n\t\tSize: medium\n");
        tempInsert (customizations);
        free(input);
        free (customizations);
        input = NULL;
        break;
    case 'L':
    case 'l':
        customizations = (char *)malloc(14);
        strcpy(customizations, "\n\t\tSize: large\n");
        tempInsert (customizations);
        free (customizations);
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
    char *File = (char *)malloc(strlen("..\\text\\custoptions.txt") + 1);
    strcpy(File, "..\\text\\custoptions.txt");
    customRead(File);
    printf("Press 0 for done");
     home(File);

    //After that, we will recursively as the user if they would like to add
    // more  to their order

}


