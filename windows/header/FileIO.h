//
// Created by shivengaddam on 11/30/23.
//

#ifndef STARBUCKSC_FILEIO_H
#define STARBUCKSC_FILEIO_H

void readFile(char fileName[], int path);
void categories(char *File);
void splitter(char item[] ,int path);
void picker(char *File);
void readFile(char *File, int path);
int input();
void start();
void writeFile(char *order, char *name, char *date);
extern char *File;

#endif //STARBUCKSC_FILEIO_H
