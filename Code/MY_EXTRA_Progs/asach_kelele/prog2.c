#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
int main()
{
	static int j=0;
	int id,i;
	for(i=0;i<10;i++)
	{
		id=fork();
		if(id!=0)
		{
			if(id==-1)
			{
				printf("Id =%d\n",j++);
				perror("Error Creating Process \n");
				exit(0);
			}
		}
		else
		{
			if(id==-1)
			{
				printf("Child Id =%d\n",j++);
				perror("Error Creating Process \n");
				exit(0);
			}
		}
	}
	printf("Final Id =%d\n",j++);
	while(1);
	for(i=0;i<35;i++)
	wait(NULL);
}
