#include <stdio.h>
#include <string.h>

char *_strtok(char *str, const char *delim)
{
	static char *ptr;

	if (str == NULL)
		str = ptr;
	while (*str != '\0')
	{
		if (*str == *delim)
		{
			*str = '\0';
			ptr = str+=1;
			return (str);
		}
		else
			str++;
	}
	return (NULL);
}
int main (void)
{
	char str[] = "Hello,World,This,is,an,example";
	char *token = _strtok(str, ",");

	while (token != NULL)
	{
		printf("Token: %s\n", token);
		token = _strtok(NULL, ",");
	}

	printf("Original String after strtok: %s\n", str);

	return (0);
}
