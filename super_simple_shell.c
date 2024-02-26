#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100


int main(void)
{
	char *lineptr, *argv[MAX], *token;
	int status, i;
	pid_t pid;
	ssize_t read;
	size_t n;

	n = 0;
	lineptr = NULL;
	while (1)
	{
		printf("#cisfin$ ");
		read = getline(&lineptr, &n, stdin);
		if (read == -1)
		{
			perror("Getline Error ");
			return (-1);
		}
		token = strtok(lineptr, "\n");
		for(i = 0; token != NULL; i++)
		{
			argv[i] = strdup(token);
			token = strtok(NULL, " "); 
		}
		argv[i] = NULL;
		pid = fork();
		if (pid == -1)
		{
			perror("Error: ");
			return (-1);
		}
		if (pid == 0)
		{
			execve(argv[0], argv, NULL);
		}
		else
		{
			wait(&status);
			continue;
		}
	}
	return (0);
}
