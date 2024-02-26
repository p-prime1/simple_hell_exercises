#include <stdio.h>
#include <unistd.h>


int main(void)
{
	char *argv[] = {"/bin/ls", "-l", NULL};
	printf("Before Execve\n");
	execv(argv[0], argv);
	return (0);
}
