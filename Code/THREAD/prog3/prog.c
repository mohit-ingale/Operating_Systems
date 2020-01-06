#include<stdio.h>
#include<pthread.h>

void * thread1(void *data)
{
	
	printf("hello world from thread %p \n",pthread_self());
}

int main(int argc, char *argv[])
{
	int i,j;
	i=*argv[1]-'0';
	pthread_t thd[i];
	for(j=i;j>0;j--)
	{	
		pthread_create(&thd[j],NULL,thread1,NULL);
	}
		printf("hello from main thread %p \n",pthread_self());
	
	for(j=i;j>0;j--)
		pthread_join(thd[j],NULL);
}
