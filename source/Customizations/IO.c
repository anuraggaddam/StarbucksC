#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../../header/Customize.h"
#include "../../header/FileIO.h"


void customRead(char * File){
 //This little block of code prints out each line of the file to the console.
    printf("\n\n\nloading options. please wait\n");
    sleep(1);
    printf("\nPlease choose an option below:\n");
    FILE *pFile = fopen(File,"r");
    if (pFile == NULL){
        printf("Something went wrong;");
    }
    char buffer[255];
    while(fgets(buffer, 255,pFile) != NULL){
        printf("%s" , buffer);
    }
    fclose(pFile);
    printf("\n");


}

//This method is to take a user input and the extract the value of that.
//After we extract the value, we turn it into a .txt file and then we
//can read from that file.
//After that,
void extract(char *File) {
    FILE *buff = fopen(File, "r");
    if (buff == NULL) {
        printf("Error opening file. Please check the file path and try again.\n");
        return;
    }

    int choice = input();
    char option[50];
    sprintf(option, "%d", choice);

    char buffered[255];
    char *op = NULL;

    while (fgets(buffered, sizeof(buffered), buff) != NULL) {
        if (strstr(buffered, option) != NULL) {
            op = (char *)malloc(strlen(buffered) + 1);
            strcpy(op, buffered);
            break;
        }
    }

    fclose(buff);

    if (op != NULL) {
        printf("Item: %s\n", op);
        free(op); // Free allocated memory
    } else {
        printf("Option not found. Try Again\n");
        // You might want to consider using a loop instead of recursion
        // to repeatedly prompt the user for a valid option.
    }
}

