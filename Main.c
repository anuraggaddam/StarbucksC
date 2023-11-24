#include <stdio.h>
#include <unistd.h>



//This method is used to print any menu or text file out.
void print(char fileName[]){
    printf("\n\n\nloading options. Please wait\n");
        sleep(2);
                printf("\nPlease choose an option below:\n");
    FILE *pFile = fopen(fileName,"r");
    char buffer[255];
        while(fgets(buffer, 255,pFile) != NULL){
            printf("%s" , buffer);
        }
    fclose(pFile);
}



//reusable cinput method. This method allows for unlimited picking
int input(){
    int choice;
    printf("\nPlease make a choice\n");
    scanf("%d", &choice);
    return choice;
}





void categories(){

    print("category.txt");
    int choice;
    choice = input();

    switch (choice){
        case 1:
        print("hcoffee.txt");
        break;
        case 2:
        print("htea.txt");
        break;
        case 3:
        print("hdrink.txt");
        break;
        case 4:
        print("frapblendbev.txt");
        break;
        case 5: 
        print("ccoffee.txt");
        break;
        case 6:
        print("itea.txt");
        break;
        case 7:
        print("cdrink.txt");
        break;
        case 8:
        print("hbreak.txt");
        break;
        case 9:
        print("bake.txt");
        break;
        case 10:
        print("lunch.txt");
        break;
        case 11:
        print("snack.txt");
        break;
        case 12:
        print("oatsyog.txt");
        break;
    
    }
}










int main(){

    printf("\nHello consumer. Welcome to Starbucks!\n");

    categories();
    return 0;
}



