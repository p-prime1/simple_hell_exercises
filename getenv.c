#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct Node {
	char *path;
	struct Node *next;
} Node;

extern char **environ;

char *_getenv(const char *name)
{
	char *holder;
	int i = 0;
	while ((holder = environ[i]) != NULL)
	{
		if ((*holder) == (*name))
			return (holder);
		i++;
	}
	return (NULL);
}

int main(void)
{
	char *token;
	struct Node *path;
	struct Node *Head;
	struct Node *temp;
	char *username = getenv("PATH");

	path = malloc(sizeof(Node));
	Head = path;
	temp = Head;
  	if (username != NULL) {
		token = strtok(username, ":");
		while (token != NULL)
		{
			Head->path = token;
			Head->next = malloc(sizeof(Node));
			Head = Head->next;
			printf("%s\n", token);
			token = strtok(NULL, ":");
		}
		Head->next = NULL;
	}
	while (temp != NULL)
	{
		printf("%s\n", temp->path);
		temp = temp->next;
	}
	return 0;
}
