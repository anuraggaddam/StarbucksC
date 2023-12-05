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
char * extract(char *File) {
    FILE *buff = fopen(File, "r");
    if (buff == NULL) {
        printf("Error opening file. Please check the file path and try again.\n");
        extract(File);
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

      char *end = (char *) malloc(strlen(File));
      int index = 0;
    if (op != NULL) {
       for (int i = 3; i < strlen(op); i++) {
        end[index] = op[i];
        index++;
    }
        end[index] = '\0';

         size_t len = strlen(end);
    if (len > 0 && end[len - 1] == '\n') {
        end[len - 1] = '\0';
    }

    free(op); // Free allocated memory
    } else {
        printf("Option not found. Try Again\n");
        extract(File);
        // You might want to consider using a loop instead of recursion
        // to repeatedly prompt the user for a valid option.
    }
    return end;

}



void home(char *File){  
    char *name = (char *) malloc(sizeof(char)*10);
    char *path = (char*)malloc(sizeof(char)*15);
    name = extract(File);
    path = stringToFileConverter(name);

    //Now we have the file path in the variable path.
    //We should send it to the read

   customRead(path);
   char *option = malloc(sizeof(char)*20);
   option = extract(path);
   addcustom(option);


    
}




char *stringToFileConverter(char *item) {
    // Allocate enough memory for the concatenated strings and null terminator
    char *myFile = (char *)malloc(strlen("../text/") + strlen(item) + strlen(".txt") + 1);
    // Copy the strings
    strcpy(myFile, "../text/");
    strcat(myFile, item);
    strcat(myFile, ".txt");
    return myFile;
}



void addcustom(char *option){

   int * number;
    number = malloc(sizeof(int));
    printf("How many packets of %s do you want?\n",option);
    scanf("%d",number);
    char *numberString = malloc(sizeof(char)*10);
    sprintf(numberString, "%d", *number);
    check(option,numberString);
    //tempIterate();
    /////////////////////
    again();    
    

}


void again(){

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
        tempInsert (product);
        tempIterate();
        break;
    default:
        again();
        break;
    }


}

