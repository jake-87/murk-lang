#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/tokeniser.h"
char ** tokenise(char * buf, int size, char *** args)
{
	printf("In tokeniser\n");
	int i = 0,tmp2 = 0,j;
	char c,n,k,tmp;
	char ** tokens = malloc(sizeof(char) * size);
	if (!tokens)
	{
		printf("malloc failed\n");
		exit(1);
	}
	printf("Malloc did the thing\n");
	// Possible tokens: int[], float[], char[], string[], print[], scan[], $memadr$
	while (i < size)
	{
		printf("in while loop\n");
		c = buf[i];
		n = buf[i + 1];
		k = buf[i + 2];
		printf("var alloc did the thing, i is %d\n",i);
		switch (c)
		{
			case '$':
				printf("case works");
				if (k == 'x')
				{
					printf("in k function");
					tokens[i] = "MEMADR";
					j = i + 2 + 1;
					tmp2 = 0;
					printf("var alloc did the thing");
					while (tmp2 != -1)
					{
						tmp = buf[tmp2 + 3];
						if (tmp == '$')
						{
							tmp2 = 0;
							continue;
						}
						* args[i][tmp2] = buf[j];
						i++;
					}
				}
			default:
				printf("Defaulted to i++.");
				i++;
		}
	}
	for (i = 0; i <= tmp2; i++)
	{
		printf("Attempting print of args\n");
		printf("%s\n",args[tmp2]);
	}
	return tokens;
}
