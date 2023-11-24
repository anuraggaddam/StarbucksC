#include <stdio.h>


void printMenu(){

    printf("Hello consumer. Welcome to Starbucks!\n");

    FILE *pMenu = fopen("category.txt","r");
    char buffer[255];


        while(fgets(buffer, 255,pMenu) != NULL){
            printf("%s" , buffer);
        }


    fclose(pMenu);

}





int main(){


    printMenu();
    return 0;
}



