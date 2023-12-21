#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "..\\..\\header\\FileIO.h"
#include "..\\..\\header\\Customize.h"
#include "..\\..\\header\\Basket.h"




char *temp;


void categories(char *File){
    int selection= input();



    switch (selection){
        case 0:
            iterate();
            break;
        case 1:
            File = (char *) realloc(File,strlen("..\\text\\hcoffee.txt")+1);
            strcpy(File, "..\\text\\hcoffee.txt");
            readFile(File,1);
            break;
        case 2:
            File =  (char *) realloc(File,strlen("..\\text\\htea.txt")+1);
            strcpy(File, "..\\text\\htea.txt");
            readFile(File, 1);
            break;
        case 3:
            File =(char *) realloc(File,strlen("..\\text\\hdrink.txt")+1);
            readFile("..\\text\\hdrink.txt",1);
            break;
        case 4:
            File = (char *)realloc(File,strlen("..\\text\\frapblendbev.txt")+1);
            strcpy(File,"..\\text\\frapblendbev.txt");
            readFile(File,1);
            break;
        case 5:
            File = (char *) realloc(File,strlen("..\\text\\ccoffee.txt")+1);
            strcpy(File, "..\\text\\ccoffee.txt");
            readFile(File,1);
            break;
        case 6:
            File = (char *)realloc (File,strlen("..\\text\\itea.txt")+1);
            strcpy(File, "..\\text\\itea.txt");
            readFile(File,1);
            break;
        case 7:
            File = (char *) realloc(File,strlen("..\\text\\cdrink.txt")+1);
            strcpy(File, "..\\text\\cdrink.txt");
            readFile(File,1);
            break;
        case 8:
            File = (char *) realloc(File,strlen("..\\text\\hbreak.txt")+1);
            strcpy(File, "..\\text\\hbreak.txt");
            readFile(File,1);
            break;
        case 9:
            File = (char *) realloc(File,strlen("..\\text\\bake.txt")+1);
            strcpy(File, "..\\text\\bake.txt");
            readFile(File,1);
            break;
        case 10:
            File = (char *) realloc(File,strlen("..\\text\\lunch.txt")+1);
            strcpy(File,"..\\text\\lunch.txt");
            readFile(File,1);
            break;
        case 11:
            File = (char *) realloc(File,strlen("..\\text\\snack.txt")+1);
            strcpy(File, "..\\text\\snack.txt");
            readFile(File,1);
            break;
        case 12:
            File = (char *)realloc(File,strlen("..\\text\\oatsyog.txt")+1);
            strcpy(File,"..\\text\\oatsyog.txt");
            readFile(File,1);
            break;
            default:
            printf("please try again");
            categories(File); 
            break;
    
    }
}



void splitter(char *item ,int path) {
    char *end = (char *) malloc(strlen(item)-3); 
    int index = 0;

if (path == 1){
  for (int i = 3; i < strlen(item)-1; i++) {
        end[index] = item[i];
        index++;
    }
}else{
      for (int i = 4; i < strlen(item)-1; i++) {
        end[index] = item[i];
        index++;
    }
}
    end[index] = '\0';
    free(item);
    item = NULL;
   char fin [50];
   strcat(fin, "\t");
   strcat(fin,end);
    tempInsert (fin);
    customize(end);

}




void picker(char *File ){
    
    FILE *buffFile = fopen(File, "r");
    if (buffFile == NULL){
        printf("Something is broken in the picker method. Please debug");
        return;
    }



    int choice = input();
    char option[50];  
    sprintf(option, "%d", choice);

    char buffer[255];
    char *item;

    while (fgets(buffer, sizeof(buffer), buffFile) != NULL) {
        if (strstr(buffer, option) != NULL) {
            item = (char *) malloc(strlen(buffer)+1);
             strcpy(item, buffer);
            break;
        }
    }
    fclose(buffFile);
  
    if (strlen(item) == 0){
        printf("Option not found. Try Again\n");
        picker(File);
    } 
 else{
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

    printf("\n\n\nloading options. please wait\n");
    sleep(1);
    printf("\nPlease choose an option below:\n");
    printf("\nClick 0 for Basket\n");
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


    if (path == 0){
        categories(File);
    }

        
    else if (path == 1){
        picker(File);
    }

}

