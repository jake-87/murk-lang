#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/tokeniser.h"
char ** tokenise(char * buf, int size, char (* args)[100][100])
{
	printf("In tokeniser\n");
	int i = 0;
	char c;
	int indextmp = 0;
	int indexer = 0;
	char ** tokens = malloc(sizeof(* tokens) * size);
	if (!tokens)
	{
		printf("calloc failed\n");
		exit(1);
	}
	printf("Malloc did the thing\n");
	for (i = 0; i < size; i++)
	{
		printf("buf[i] is %c\n",buf[i]);
	}
	// Possible tokens: int[], float[], char[], string[], print[], scan[], $memadr$
	i = 0;
	while (i < size)
	{
		c = buf[i];
		switch (c)
		{
			case '$':
				if (buf[i + 2] == 'x')
				{
					indextmp = 0;
					i = i + 3;
					int oldi = i;
					while (buf[i] != '$')
					{
						(* args)[oldi][indextmp] = buf[i];
						indextmp++;
						indexer++;
						i++;
					}
				}
			default:
				printf("Defaulting to i++;\n");
				i++;
		}
	}
	return tokens;
}
