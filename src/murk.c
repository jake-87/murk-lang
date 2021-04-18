#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/utils.h"
#include "../include/tokeniser.h"
int main(int argc, char ** argv)
{
	int size;
	if (argc < 3)
	{
		printf("Too few args. At least 3 required.\n");
		return -1;
	}
	if (strcmp(argv[1],"compile") == 0)
	{
		char * buf = readFromFile(argv[2],&size);
		printf("%s\n",buf);
		char stringarglist[100][100];
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				stringarglist[i][j] = 0;
			}
		}
		tokenise(buf, size, &stringarglist);
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				printf("%d;%d : %c\n",i,j,stringarglist[i][j]);
			}
		}
		free(buf);
	}
	return 0;
}
