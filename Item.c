#include "Item.h"
#include <stdio.h>


void print_item(Item i)
{
	printf("%d %s %s\n", i.id, i.nr, i.name);
}

int item_isEqual(Item a, Item b)
{
	return a.id == b.id;
}