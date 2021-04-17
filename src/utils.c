#include "../include/utils.h"
#include <stdio.h>
#include <stdlib.h>
char * readFromFile(char * filePath, int * size)
{
	FILE * file;
	file = fopen(filePath,"r");
	if (!file)
	{
		printf("File could not be opened.\n");
		exit(1);
	}
	fseek(file, 0L, SEEK_END);
	* size = ftell( file );
	printf("%d\n",* size);
	rewind(file);
	char * buf = calloc(1,* size + 1);
	if (!buf)
	{
		fclose(file);
		fprintf(stderr,"ERROR: Memory alloc failed!");
		exit(1);
	}
	if ( 1 != fread(buf, * size, 1, file) )
	{
		fclose(file);
		fprintf(stderr, "ERROR: Read file failed!");
		exit(1);
	}
	fclose(file);
	return(buf);

}
