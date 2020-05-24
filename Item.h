#ifndef __item__h__
#define __item__h__
#define NAME_SZ 64
#define NR_SZ 16

typedef struct {
	int id;
	char nr[NR_SZ];
	char name[NAME_SZ];
} Item;


void print_item(Item i);
int item_isEqual(Item, Item);

#endif