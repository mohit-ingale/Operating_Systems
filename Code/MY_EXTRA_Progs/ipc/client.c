#include<stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

struct fifon{
	char PRIVATE[50];
	char cmd[10];
};

int main()
{
	struct fifon cli;
	char buff[1000];
	int fd,fr,n;
	sprintf(cli.PRIVATE,"client%d",getpid());
	if((mknod(cli.PRIVATE,S_IFIFO|0666,0))<0)
	{
		perror("fifo\n");
		exit(1);
	}
	if((fd=open("PUBLIC",O_WRONLY))==-1)
	{
		perror("Error Opening file\n");
		exit(1);
	}
	while(1)
	{
		memset(buff,0x00,sizeof buff);
		puts("Enter command to execute");
		n=read(0,cli.cmd,sizeof cli.cmd);
		if(strncmp(cli.cmd,"quit",n-1)==0)
		{
			printf("User Quited\n");
			break;
		}
		write(fd,(char *)&cli,sizeof cli);
		if((fr=open(cli.PRIVATE,O_RDONLY))==-1)
		{
			perror("Error Opening file\n");
			exit(1);
		}
	
		while((n=read(fr,buff,sizeof(buff)))>0)
			puts(buff);
		close(fr);
	}
	unlink(cli.PRIVATE);
	return 0;
}
