#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
	int fd;
	char buff[10];
	if((fd=open("fifo_1",O_RDONLY))==-1)
	{
		perror("error making fifo\n");
		exit(1);
	}
	puts("Open Successfull\n");
	read(fd,buff,sizeof(buff));
	puts(buff);
}
