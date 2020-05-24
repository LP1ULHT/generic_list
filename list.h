#include "Item.h"

#ifndef __list__h__
#define __list__h__


typedef struct node * link;
struct node {
	Item item; 
	link next;
};

void listInit(link *);
int	isEmpty(link);
Item FIFOremove(link *);
Item LIFOremove(link *);
int FIFOinsert(link *, Item);
int LIFOinsert(link *, Item);

void list(link);

Item * searchItem(link, Item);
void clearList(link *);

#endif
