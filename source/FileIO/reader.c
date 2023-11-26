#include <stdio.h>
#include <unistd.h>






void categories(){
    int choice;
    choice = input();

    switch (choice){
        case 1:
            readFile("../../text/hcoffee.txt",1 );
            break;
        case 2:
            readFile("../../text/htea.txt"),1;
            break;
        case 3:
            readFile("../../text/hdrink.txt",1);
            break;
        case 4:
            readFile("../../text/frapblendbev.txt",1);
            break;
        case 5: 
            readFile("../../text/ccoffee.txt",1);
            break;
        case 6:
            readFile("../../text/itea.txt",1);
            break;
        case 7:
            readFile("../../text/cdrink.txt",1);
            break;
        case 8:
            readFile("../../text/hbreak.txt",1);
            break;
        case 9:
            readFile("../../text/bake.txt",1);
            break;
        case 10:
            readFile("../../text/lunch.txt",1);
            break;
        case 11:
            readFile("../../text/snack.txt",1);
            break;
        case 12:
            readFile("../../text/oatsyog.txt",1);
            break;
            default:
            printf("please try again");
            categories(); // if invalid option is entered, call the method again. This prompts the user for input again.
            break;
    
    }
}


void splitter(char item[] ,int path) {
    char end[255] = {'\0'};  // Initialize the array and null-terminate it
    int index = 0;

if (path == 1){
  for (int i = 3; i < strlen(item); i++) {
        end[index] = item[i];
        index++;
    }
}else{
      for (int i = 4; i < strlen(item); i++) {
        end[index] = item[i];
        index++;
    }
}
  

    printf("\nYou have chosen:\n%s\n", end);

/*

This is where I create the basket library and create a temp function that stores this and gathers customization options
I shall call this method and pass through end. 

*/

}




void picker(char FileName[] ){
    
    FILE *pFile = fopen(fileName, "r");


//This asks for user input and converts it into a string. 
    int choice = input();
    char option[10];  // Adjust the size based on the maximum length of the option
    sprintf(option, "%d", choice);

    char buffer[255];
    char item[]="";// This should store the line that holds 

    while (fgets(buffer, sizeof(buffer), pFile) != NULL) {
        if (strstr(buffer, option) != NULL) {
             strcpy(item, buffer);
            break;
        }
    }
    fclose(pFile);

    //If user did invalid option, we should call the method again an dcheck for verificatoin
    if (strlen(item) == 0){
        printf("Empty\n");
        picker(fileName);
    } 
    //Otherwise we will trim the array to take out the number in the first bit
 else{
    if (choice >=10){
        splitter(item,0);
    }
    
 }

    return 0;
}







//This method just reads the file that is being sent through
void readFile(char fileName[], int path){


 //This little block of code prints out each line of the file to the console.
  printf("\n\n\nloading options. Please wait\n");
        sleep(1);
            printf("\nPlease choose an option below:\n");
                   FILE *pFile = fopen(fileName,"r");
    char buffer[255];
        while(fgets(buffer, 255,pFile) != NULL){
            printf("%s" , buffer);
        }
    fclose(pFile);
       printf("\n");


        //a path of 0 will call the function that sorts out what category file to print out
            if (path == 0){
                categories();
            }

        //a path of 1 will cycle through each line and send pick which one matches. If there is no match, ask user again.
        //Create another method in this file for that. 
            if (path == 1){
                picker(fileName); 
            }

}


