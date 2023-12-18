#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "../../header/Basket.h"
#include "../../header/FileIO.h"


void count(node *orderNode){
	int small = 0;
	int medium = 0;
	int large = 0;
	int *pSmall = &small;
	node *cur = orderNode;

	if (orderNode == NULL){
		printf("Cart empty. Returning to menu...");
		start();
	}
	while(cur != NULL){
		if ( strstr(cur->order, "large") != NULL){
			large++;
		}
		if ( strstr(cur->order, "small") != NULL){
			small++;
		}
		if ( strstr(cur->order, "medium") != NULL){
			large++;
		}
		cur = cur->next;
	}



}


