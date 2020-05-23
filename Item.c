#include "item.h"
#include <stdio.h>


void print_item(Item i)
{
	printf("%d %d %s\n", i.id, i.number, i.name);
}