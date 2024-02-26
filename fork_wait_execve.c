#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
	int i, status;
	pid_t pid;
	char *argv[] = {"/bin/ls", "-l", "/tmp/", NULL};

	for (i = 0; i < 5; i++)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("Error:");
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

