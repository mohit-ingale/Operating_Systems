#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<stdlib.h>
#include <fcntl.h>
 #include <unistd.h>
#define MAX 1024
int main()
{
	int id1,id2,size,fd1,fd2;
	char buff[MAX];
	id1=mkfifo("pipe1",0660);
	id2=mkfifo("pipe2",0660);
	fd1=open("pipe1",O_RDONLY);
	if(fd1==-1)
	{
		perror("Error opening pipe1:\n");
		exit(EXIT_FAILURE);
	}
	fd2=open("pipe2",O_WRONLY);
	if(fd2==-1)
	{
		perror("Error opening pipe2:\n");
		exit(EXIT_FAILURE);
	}
	size=read(fd1,buff,MAX);
	if(size==-1)
	{
		perror("Error reading\n");
		exit(EXIT_FAILURE);
	}
	printf("%s\n",buff);
	size=write(fd2,"HI",2);
	if(size==-1)
	{
		perror("Error writing\n");
		exit(EXIT_FAILURE);
	}
	
	return 0;
}
