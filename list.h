#include "Item.h"

#ifndef __list__h__
#define __list__h__


typedef struct node * link;
struct node {
	Item item; 
	link next;
};

int	isEmpty(link);
Item FIFOremove(link * head_ptr);
Item LIFOremove(link * head_ptr);
int FIFOinsert(link * head_ptr, Item i);
int LIFOinsert(link * head_ptr, Item i);

void list(link * head_ptr);
//Item search()


#endif
