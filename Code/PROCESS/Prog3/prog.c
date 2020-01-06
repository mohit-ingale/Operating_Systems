#include<stdio.h>
#include <unistd.h>
int main()
{
	int id;
	printf("\ni am the Parent and my ID is %d\n",getpid());
	id=fork();
	if(id==0)
	{
		printf("child1 pid=%d\tchild1 ppid=%d\n",getpid(),getppid());
		id=fork();
		if(id==0)
		{
			printf("child1_1 pid=%d\tchild1_1 ppid=%d\n",getpid(),getppid());
		}
		else
		{
			id=fork();
			if(id==0)
			{
				printf("child1_2 pid=%d\tchild1_2 ppid=%d\n",getpid(),getppid());
			}
		}
	}
	else
	{
		id=fork();
		if(id==0)
		{
			printf("child2 pid=%d\tchild2 ppid=%d\n",getpid(),getppid());
			id=fork();
			if(id==0)
			{
				printf("child2_1 pid=%d\tchild2_1 ppid=%d\n",getpid(),getppid());
			}
			else
			{
				id=fork();
				if(id==0)
				{
					printf("child2_2 pid=%d\tchild2_2 ppid=%d\n",getpid(),getppid());
				}
			}
		}
	}
	wait(NULL);
	return 0;
}



