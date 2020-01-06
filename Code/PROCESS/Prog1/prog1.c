#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
	int i;
	for(i = 0; i <3; i++)
	{
		pid_t pid = fork();
		printf("I am process %d, My parent is %d\n",getpid(),getppid());
	}
}
