#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	pid_t ppid;
	pid_t child_pid;
	int status;

	ppid = getpid();
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return (-1);
	}

	if (child_pid == 0)
	{
		printf("Child process running %u\n PArent id %u\n", child_pid, ppid);
		sleep(5);
	}
	else
	{
		wait(&status);
		printf("All done %u\n Parents is %u\n", child_pid, ppid);
	}
	return (0);
}

