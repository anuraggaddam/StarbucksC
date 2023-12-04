
#ifndef STARBUCKSC_CUSTOMIZE_H
#define STARBUCKSC_CUSTOMIZE_H

void customize(char *item);
void size();
void options();
void customRead(char *File);
char * extract(char *File);
void home(char *File);
char * stringToFileConverter(char *item);
void addcustom(char *option);
void tempIterate();
void tempInsert(char *option);

extern char *product;
extern char *customizations;
extern char *temp;

typedef struct tempCustomizationsList{
  char *data;
  struct tempCustomizationsList *next;
}tempcustomizationsList;

extern tempcustomizationsList *head;



#endif //STARBUCKSC_CUSTOMIZE_H
