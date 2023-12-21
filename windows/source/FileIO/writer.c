#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../header/FileIO.h"

void writeFile(char *order, char *name, char *date){

FILE *file;

char filename[200] = ".\\receipts\\";
strcat(filename, name);
strcat(filename, " ");
strcat(filename, date);

file = fopen(filename, "w");

fprintf(file, "%s", order);
}