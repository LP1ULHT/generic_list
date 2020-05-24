#include <stdlib.h>
#include <assert.h>

#include "list.h"

Item removeLink(link *);


void listInit(link *head_ptr)
{
	*head_ptr = NULL;
}

int	isEmpty(link head)
{
	return head == NULL;
}

// insert after node
int	insert(link *node, Item i)
{ 
	link t = (link) malloc(sizeof(*t));
	if (t == NULL)
		return 0;
	
	t -> item = i;

	if (*node == NULL)
		t -> next = NULL;
	else	
		t->next = *node;

	*node = t;

	return 1;
}


Item removeLink(link * t)
{
	Item i;
	link aux;
	aux = *t;
	assert(aux != NULL);
	i = aux -> item;
	*t = aux -> next;
	free(aux);
	return i;
}

Item FIFOremove(link * head_ptr)
{
	// remove first element
	return removeLink(head_ptr);
}

Item LIFOremove(link * head_ptr)
{
	// remove first element
	return removeLink(head_ptr);
}

int FIFOinsert(link * head_ptr, Item i)
{
	// insert at the end of list
	link t;
	if (*head_ptr == NULL)
		return insert(head_ptr, i);
	

	for (t = *head_ptr ; t->next != NULL; t = t -> next);

	return insert(&(t -> next), i);

}
int LIFOinsert(link * head_ptr, Item i)
{
	// insert at the top of the list
	return insert(head_ptr, i);
}

void list(link head_ptr)
{
	link t;
	for (t = head_ptr ; t != NULL; t = t -> next)
	{
		print_item(t->item);
	}
}

// in case you want do search and delete a specific link
// you need to search and return the pointer to the link
// instead of the pointer to the item.
Item * searchItem(link head, Item i)
{
	link t;
	for (t = head ; t != NULL; t = t -> next)
	{
		if (item_isEqual(t->item, i))
			return &(t->item);
	}
	return NULL;
}

void clearList(link *head_ptr)
{
	while (!isEmpty(*head_ptr))
		removeLink(head_ptr);
}

