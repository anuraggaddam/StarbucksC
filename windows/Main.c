#include <stdio.h>
#include "./header/FileIO.h"
#include <stdlib.h>
#include <string.h>
#include "./header/Customize.h"
#include <unistd.h>

char *File;
int main(){
    printf("\nHello customer. Welcome to Starbucks!\n");
    printf("Small drinks are $3, Medium Drinks are $4 and Large Drinks are $5\n");
    sleep(2);

   start();

    return 0;
}

void start(){
     File = (char *) malloc(strlen("..\\text\\category.txt")+1);

    strcpy(File, "..\\text\\category.txt");

    readFile(File,0);
}

