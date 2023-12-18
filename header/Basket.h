
#ifndef STARBUCKSC_BASKET_H
#define STARBUCKSC_BASKET_H

typedef struct node{
    char *order;//When we set value to order. Make sure to copy the contents and make other variable null;
    struct node *next; //
}node;


extern node *top;
void insert(char *orderString);
void iterate();
void afterBasket();
void delete();
int checkSize();

void count(node *orderNode);
void calculate(int *s, int *m, int *l, node *orderNode);
void info(int *total, node *orderNode);

#endif //STARBUCKSC_BASKET_H
