#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "Item.h"
#include "list.h"

//#define LIFO
#define FIFO


#define OPT_REM 'R'
#define OPT_ADD 'N'
#define OPT_LIST 'L'
#define OPT_QUIT 'Q'
#define OPT_SEARCH 'S'

#define DIM 256

void readfile(char *, link *);

int main(int argc, char **argv)
{
	link head;
	Item aux;
	Item * item_ptr;

	listInit(&head);
	
	char input[DIM];
	char option;

	if (argc < 2)
	{
		puts("error: invalid arguments");
		exit(1);
	}

	readfile(argv[1], &head);


	list(head);

	while(1)
	{
		putchar('>');
		fgets(input, DIM, stdin);

		if (sscanf(input, " %c ", &option) != 1)
			continue;

		switch(toupper(option))
		{
		case OPT_REM:
			if (!isEmpty(head))
			{
				#ifdef FIFO
				aux = FIFOremove(&head);
				#else
				aux = LIFOremove(&head);
				#endif

				puts("ok removed item:");
				print_item(aux);
			}
			else
				puts("The queue is empty");
			continue;

		case OPT_ADD:
			if (sscanf(input, " %c %s %d %[^\n]", &option, aux.nr, &aux.id, aux.name) != 4)
			{
				printf("Sintax: '%c' <nr> <id> <name>\n", OPT_ADD);
				continue;
			}
		
			#ifdef FIFO
			FIFOinsert(&head, aux);
			#else
			LIFOinsert(&head, aux);
			#endif				

		case OPT_LIST:
			list(head);
			continue;

		case OPT_QUIT:
			exit(0);


		case OPT_SEARCH:
			memset(&aux, 0, sizeof(Item));
			if (sscanf(input, " %c %d", &option, &aux.id) != 2)
			{
				printf("Sintax: '%c' <id>\n", OPT_SEARCH);
				continue;
			}
			item_ptr = searchItem(head, aux);
			if (item_ptr == NULL)
				puts("Sorry, Item not found");
			else
			{
				puts("Urray, found the following Item:");
				print_item(*item_ptr);
			}

		default:
			puts("unknown option");

		}
	}

	clearList(&head);

	exit(0);
}

void readfile(char * fname, link * head_ptr)
{
	Item aux;
	FILE * fp = NULL;

	fp = fopen(fname, "r");
	if (fp == NULL)
	{
		puts("error: could not open file");
		exit(1);
	}

	while (!feof(fp))
	{
		if (fscanf(fp, "%s %d %[^\n]", aux.nr, &aux.id, aux.name) != 3)
			continue;

		if (!FIFOinsert(head_ptr, aux))
		{
			puts("Error: out of memory!");
			exit(1);
		}
	}
}