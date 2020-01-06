#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc,char *argv[])
{
	FILE *frd,*fwr;
	int n;
	char buff[50];
	if(argc<3)
	{
		printf("Enter all Commands\n");
		exit(1);
	}
	frd=popen(argv[1],"r");
	fwr=popen(argv[2],"w");
	fflush(fwr);
	while((n=read(fileno(frd),buff,sizeof(buff)))>0)
		write(fileno(fwr),buff,n);
	pclose(frd);
	pclose(fwr);
}
