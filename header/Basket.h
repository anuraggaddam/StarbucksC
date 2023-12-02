
#ifndef STARBUCKSC_BASKET_H
#define STARBUCKSC_BASKET_H

typedef struct node{
    char *order;//When we set value to order. Make sure to copy the contents and make other variable null;
    node *next; //
}node;


extern node *head;


#endif //STARBUCKSC_BASKET_H
