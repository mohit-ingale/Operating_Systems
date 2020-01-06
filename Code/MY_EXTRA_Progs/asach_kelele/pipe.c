#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int fd[2],writefd,readfd,id;
	char buff[50];
	if(pipe(fd)==-1)
	{
		perror("Error Creating pipe\n");
		exit(EXIT_FAILURE);
	}
	id=fork();
	if(id==0)
	{
		dup2(fd[1],fileno(stdout));
		close(fd[1]);
		close(fd[0]);
		/*if(write(fileno(stdout),"hellohowal",10)==-1)
		{
			perror("Error Writing\n");
			exit(1);
		}
		//while(1);*/
		printf("heopsohowal");
	}
	else
	{
		dup2(fd[0],fileno(stdin));
		close(fd[0]);
		close(fd[1]);
		scanf("%s",buff);
		//read(fileno(stdin),buff,sizeof(buff));
		puts(buff);
		//scanf("%s",buff);
		//read(fileno(stdin),buff,sizeof(buff));
		//puts(buff);
	}
	wait(NULL);
}
