#include<stdio.h>
#include<unistd.h>

int main()
{
	int id;   
	id = fork();
	if(0==id)
	{
		sleep(1);
	}
	else
	{
		id=fork();
		if(0==id)
		{
			sleep(1);
		}
	}
	printf("Process Id=%d \t Parent Process Id=%d\n",getpid(),getppid());
	wait(NULL);
}

