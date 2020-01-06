#include<pthread.h>
#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
pthread_t pid;
pthread_attr_t atr;
void *task1(void *data)
{
	printf("This is Thread\npid=%d\nppid=%d\ntid=%p\n",getpid(),getppid(),pthread_self());
	//while(1);
}

int main()
{
	if(pthread_create(&pid,NULL,task1,NULL)!=0)
		{
			perror("Error Creating Thread\n");
			exit(1);
		}
	printf("This is main Thread\npid=%d\nppid=%d\ntid=%p\n",getpid(),getppid(),pthread_self());
		pthread_join(pid,NULL);
	
	
}
