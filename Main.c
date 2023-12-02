#include <stdio.h>
#include "./header/FileIO.h"
#include <stdlib.h>
#include <string.h>
char *File;
int main(){

    printf("\nHello consumer. Welcome to Starbucks!\n");

    File = (char *) malloc(strlen("../text/category.txt")+1);

    strcpy(File, "../text/category.txt");

    readFile(File,0);
    return 0;
}



