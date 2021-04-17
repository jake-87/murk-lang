#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/utils.h"
#include "../include/tokeniser.h"
int main(int argc, char ** argv)
{
	int size;
	char ** args;
	if (argc < 3)
	{
		printf("Too few args. At least 3 required.\n");
		return -1;
	}
	if (strcmp(argv[1],"compile") == 0)
	{
		char * buf = readFromFile(argv[2],&size);
		printf("%s\n",buf);
		tokenise(buf, size, &args);
		free(buf);
	}
	return 0;
}
