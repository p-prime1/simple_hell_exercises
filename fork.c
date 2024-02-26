#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t my_pid;
	pid_t pid;

	printf("Before fork\n");
	my_pid = getpid();
	pid = fork();
	if (pid == -1)
	{
		perror("Error:");
		return (1);
	}
	if (pid == 0)
		printf("My pid is %u\n (%u) Child process\n", my_pid, pid);
	else
	{
		printf("(%u), my pid child pid is %u\n", my_pid, pid);
	}

	return (0);
}
