#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../../header/FileIO.h"
#include "../../header/Customize.h"




char *temp;

//When the main function is ran in the Main.c file, this will end up getting called.
//This is where the user can choose their category and this method will send the corresponding file to print
void categories(char *File){
    int selection= input();



    switch (selection){
        case 1:
            File = (char *) realloc(File,strlen("../text/hcoffee.txt")+1);
            strcpy(File, "../text/hcoffee.txt");
            readFile(File,1);
            break;
        case 2:
            File =  (char *) realloc(File,strlen("../text/htea.txt")+1);
            strcpy(File, "../text/htea.txt");
            readFile(File, 1);
            break;
        case 3:
            File =(char *) realloc(File,strlen("../text/hdrink.txt")+1);
            readFile("../text/hdrink.txt",1);
            break;
        case 4:
            File = (char *)realloc(File,strlen("../text/frapblendbev.txt")+1);
            strcpy(File,"../text/frapblendbev.txt");
            readFile(File,1);
            break;
        case 5:
            File = (char *) realloc(File,strlen("../text/ccoffee.txt")+1);
            strcpy(File, "../text/ccoffee.txt");
            readFile(File,1);
            break;
        case 6:
            File = (char *)realloc (File,strlen("../text/itea.txt")+1);
            strcpy(File, "../text/itea.txt");
            readFile(File,1);
            break;
        case 7:
            File = (char *) realloc(File,strlen("../text/cdrink.txt")+1);
            strcpy(File, "../text/cdrink.txt");
            readFile(File,1);
            break;
        case 8:
            File = (char *) realloc(File,strlen("../text/hbreak.txt")+1);
            strcpy(File, "../text/hbreak.txt");
            readFile(File,1);
            break;
        case 9:
            File = (char *) realloc(File,strlen("../text/bake.txt")+1);
            strcpy(File, "../text/bake.txt");
            readFile(File,1);
            break;
        case 10:
            File = (char *) realloc(File,strlen("../text/lunch.txt")+1);
            strcpy(File,"../text/lunch.txt");
            readFile(File,1);
            break;
        case 11:
            File = (char *) realloc(File,strlen("../text/snack.txt")+1);
            strcpy(File, "../text/snack.txt");
            readFile(File,1);
            break;
        case 12:
            File = (char *)realloc(File,strlen("../text/oatsyog.txt")+1);
            strcpy(File,"../text/oatsyog.txt");
            readFile(File,1);
            break;
            default:
            printf("please try again");
            categories(File); // if invalid option is entered, call the method again. This prompts the user for input again.
            break;
    
    }
}


//This takes the string and takes out the number and period.
void splitter(char *item ,int path) {
    char *end = (char *) malloc(strlen(item)); // Initialize the array and null-terminate it
    int index = 0;

if (path == 1){
  for (int i = 3; i < strlen(item)-3; i++) {
        end[index] = item[i];
        index++;
    }
}else{
      for (int i = 4; i < strlen(item)-3; i++) {
        end[index] = item[i];
        index++;
    }
}
    end[index] = '\n';
    free(item);
    item = NULL;

    tempInsert (end);
    customize(end);

}





//This takes the file and user input and sees if there is matching option in the file.
//If there is no option, then recursion happens.
void picker(char *File ){
    
    FILE *buffFile = fopen(File, "r");
    if (buffFile == NULL){
        printf("Something is broken in the picker method. Please debug");
        return;
    }


//This asks for user input and converts it into a string. 
    int choice = input();
    char option[50];  // Adjust the size based on the maximum length of the option
    sprintf(option, "%d", choice);

    char buffer[255];
    char *item;// This should store the line that holds

    while (fgets(buffer, sizeof(buffer), buffFile) != NULL) {
        if (strstr(buffer, option) != NULL) {
            item = (char *) malloc(strlen(buffer)+1);
             strcpy(item, buffer);
            break;
        }
    }
    fclose(buffFile);
    //If user did invalid option, we should call the method again and check for verificatoin
    if (strlen(item) == 0){
        printf("Option not found. Try Again\n");
        picker(File);
    } 
    //Otherwise we will trim the array to take out the number in the first bit
 else{
     //At this point all we are sending is the item to split it. We do not need to keep the file path any longer.
     free(File);
     File = NULL;
    if (choice >=10){
        splitter(item,0);
    }
    else{
        splitter(item,1);
    }
 }


}





//This method just reads the file that is being sent through
//If it's from the main function, then we will call categories.
//otherwise we will call picker file which will take the string and break it down.
void readFile(char *File, int path){

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


    //a path of 0 will call the function that sorts out what category file to print out
    if (path == 0){
        categories(File);
    }

        //a path of 1 will cycle through each line and send pick which one matches. If there is no match, ask user again.
        //Create another method in this file for that.
    else if (path == 1){
        picker(File);
    }

}


