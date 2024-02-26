#include <stdio.h>
#include <string.h>
#include "main.h"

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t i;
	char c;

	i = 1;
	if (*lineptr == NULL)
		*lineptr = malloc(sizeof(char) * (2));
	while ((c = fgets(stream)) != EOF)
	{
		if (i > *n)
		{
			n += 1;
			*lineptr = realloc(*lineptr, *n * 2);
		}
		if ((*lineptr) == NULL)
		{
			perror("Allocation Failed");
			return (-1);
		}
		(*lineptr)[i] = c;
		i++;
	}
	i += 1;
	(*lineptr)[i] = '\0';
	return (i);
}






