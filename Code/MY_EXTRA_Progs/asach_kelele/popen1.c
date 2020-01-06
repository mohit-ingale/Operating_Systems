#include<stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	FILE *fs,*fd;
	int n;
	char buff[1000];
	fs=popen(argv[1],"r");
	fd=popen(argv[2],"w");
	while((n=read(fileno(fs),buff,sizeof buff))>0)
		write(fileno(fd),buff,n);
	pclose(fs);
	pclose(fd);
}
