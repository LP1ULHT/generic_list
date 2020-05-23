
#include <stdlib.h>
#include "list.h"


int	isEmpty(link head)
{
	return head == NULL;
}

// insert after node
int	insert(link *node, Item i)
{ 
	link aux;
	link t = (link) malloc(sizeof(*t));
	if (t == NULL)
		return 0;
	
	t -> item = i;

	if (*node == NULL)
	{
		t -> next = NULL;
	} 
	else
	{		
		t->next = (*node) -> next;
	}

	*node = t;

	return 1;
}


Item remove(link * t)
{
	Item i;
	link aux;
	aux = *t;

	if (aux == NULL)
	{
		puts("Error: cannot delete NULL link");
		exit(1);
	}
	i = aux -> item;
	*t = aux -> next;
	free(aux);
	return i;
}

Item FIFOremove(link * head_ptr)
{
	// remove first element
	return remove(head_ptr);
}

Item LIFOremove(link * head_ptr)
{
	link t;
	if (*head_ptr == NULL)
	{
		puts("Error: cannot delete node from empty list");
		exit(1);		
	}

	for (t = *head_ptr ; t->next != NULL; t = t -> next);

	return remove(&(t -> next));
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
	// insert at the top?
	return insert(head_ptr, i);
}

void list(link * head_ptr)
{
	link t;
	for (t = *head_ptr ; t != NULL; t = t -> next)
	{
		print_item(t->item);
	}
}

Item * search(link * head_ptr, Item i)
{
	link t;
	for (t = *head_ptr ; t != NULL; t = t -> next)
	{
		if (item_isEqual(t->item, i))
			return &(t->item);
	}
	return NULL;
}



