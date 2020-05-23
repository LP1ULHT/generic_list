#include <stdio.h>
#include "Item.h"
#include "list.h"

#define OPT_REM 'R'
#define OPT_ADD 'N'
#define OPT_LIST 'L'
#define OPT_QUIT 'Q'


#define DIM 256

void readfile(char *, link **);


int main(int argc, char **argv)
{
	link * head;
	Item aux;

	
	FILE * fp = NULL;
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
			FIFOremove(&head);
			continue;

		case OPT_ADD:
			if (sscanf(input, " %c %s %d %[^\n]", &option, aux.nr, &aux.id, aux.name) != 4)
				continue;
			FIFOinsert(&head, aux);

		case OPT_LIST:
			list(head);
			continue;

		case OPT_QUIT:
			exit(0);

		default:
			puts("unknown option");

		}
	}

	exit(0);
}

void readfile(char * fname, link ** head_ptr)
{
	FILE * fp = NULL;
	Item aux;

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

		if (!insert(head_ptr, aux))
		{
			puts("Error: out of memory!");
			exit(1);
		}
	}
}