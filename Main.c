#include <stdio.h>
#include "./header/FileIO.h"
#include <stdlib.h>
#include <string.h>
#include "./header/Customize.h"

char *File;
int main(){

    printf("\nHello customer. Welcome to Starbucks!");

    File = (char *) malloc(strlen("../text/category.txt")+1);

    strcpy(File, "../text/category.txt");

    readFile(File,0);
    return 0;
}



