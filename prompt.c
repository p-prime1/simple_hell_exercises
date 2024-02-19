#include <stdio.h>

int main(void)
{
	char *lineptr;
	size_t size;

	lineptr = NULL;
	size = 0;
	while (1)
	{
		printf("$");
		getline(&lineptr, &size, stdin);
		printf("%s", lineptr);
	}
	return (0);
}	
