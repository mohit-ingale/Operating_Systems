#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#define _GNU_SOURCE
#include <fcntl.h> 
#include<string.h>
#include<sys/wait.h>
#define MAX 1024
int main()
{
	pid_t id;
	int pfd1[2],pfd2[2],size;
	char buff[MAX]={'\0'};
	char file[30];
	if(pipe(pfd1)==-1)
	{
		perror("Error creating pipe\n");
		exit(EXIT_FAILURE);
	}
	if(pipe(pfd2)==-1)
	{
		perror("Error creating pipe\n");
		exit(EXIT_FAILURE);
	}
	id=fork();
	if(id==0)
	{
		close(pfd1[0]);
		close(pfd2[1]);
		printf("Enter file name:");
		gets(file);
		size=write(pfd1[1],file,strlen(file));
		if(size==-1)
		{
			perror("Error writing file name\n");
			exit(EXIT_FAILURE);
		}
		read(pfd2[0],buff,MAX);
		printf("%s\n",buff);
		exit(EXIT_SUCCESS);
	}
	else
	{
	int i;
	FILE *fp;
		close(pfd1[1]);
		close(pfd2[0]);
		size=read(pfd1[0],buff,MAX);
		if(size==-1)
		{
			perror("Error reading file name\n");
			exit(EXIT_FAILURE);
		}
		fp=fopen(buff,"r");
		if(fp==NULL)
		{
			perror("Error opening file");
			write(pfd2[1],"Error opening file\n",19);
			wait(NULL);
			exit(EXIT_FAILURE);
		}
		for(i=0;(buff[i]=getc(fp))!=EOF;i++);
		buff[i]='\0';
		write(pfd2[1],buff,MAX);
		wait(NULL);	
	}
	return 0;
}
