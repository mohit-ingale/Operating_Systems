#include<pthread.h>
#include<stdio.h>
#include <stdlib.h>
pthread_t pid;
pthread_attr_t atr;
static int i=0;
void *task1(void *data)
{
	printf("This is Thread = %d\n",i++);
	while(1);
}

int main()
{
	int i=0;
	//pthread_attr_init(&atr);
	for(i=0;i<30000;i++)
	{
		if(pthread_create(&pid,NULL,task1,NULL)!=0)
		{
			perror("Error Creating Thread\n");
			//exit(1);
		}
	}
	printf("This is main Thread\n");
	for(i=0;i<10;i++)
		pthread_join(pid,NULL);
	
	
}
