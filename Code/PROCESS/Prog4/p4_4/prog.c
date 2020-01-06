#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
	int id;   
	id = fork();
	
	if(id!=0)
	{
		id=fork();
		if(0==id)
		{
			sleep(1);
		}
		wait(NULL);
	}
	wait(NULL);
	printf("Process Id=%d \t Parent Process Id=%d\n",getpid(),getppid());
	
}

