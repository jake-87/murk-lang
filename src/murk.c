#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/utils.h"
int main(int argc, char ** argv)
{
	if (argc < 3)
	{
		printf("Too few args. At least 3 required.\n");
		return -1;
	}
	if (strcmp(argv[1],"compile") == 0)
	{
		char * buf = readFromFile(argv[2]);
		printf("%s\n",buf);
		free(buf);
	}
	return 0;
}
