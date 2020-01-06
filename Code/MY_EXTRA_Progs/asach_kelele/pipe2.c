#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int fd[2],id;
	char buff[5];
	if(pipe(fd)==-1)
	{
		perror("Error Creating pipe\n");
		exit(EXIT_FAILURE);
	}
	id=fork();
	if(id==0)
	{
		close(fd[1]);
		read(fd[0],buff,sizeof(buff));
		puts(buff);
		read(fd[0],buff,sizeof(buff));
		puts(buff);
		read(fd[0],buff,sizeof(buff));
		//while(1);
	}
	else
	{
		close(fd[0]);
		if(write(fd[1],"hellohowal",10)==-1)
		{
			perror("Error Writing\n");
			exit(1);
		}
		//
		printf("Data Written from Parent\n");
		close(fd[1]);
	
		//close(fd[0]);
		
	}
	wait(NULL);
}
