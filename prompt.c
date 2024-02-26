#include <stdio.h>
#include "main.h"

int main(void)
{
	char *lineptr;
	size_t size;

	lineptr = NULL;
	size = 0;
	while (1)
	{
		printf("$");
		_getline(&lineptr, &size, stdin);
		printf("%s", lineptr);

	}
	return (0);
}	
