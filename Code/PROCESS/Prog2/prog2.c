#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
int main()
{
	FILE *fp;
	char str[80];
	fp = fopen("plan1.txt","w");
	if(fp == NULL)
	{
		fprintf(stderr,"Could not open file");
		exit(1);
	}
	//fgets(str,80,fp);
	fputs("This line written by parent process",fp);
	//printf("Parent reads: %s\n",str);
	if(fork() == 0)
	{
	//	fgets(str,80,fp);
		fputs("This line written by child process",fp);
		//printf("Child Reads: %s\n",str);
	}
	fclose(fp);
}
