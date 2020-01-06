#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#define __USE_GNU
#include<pthread.h>





int count=0;
pthread_mutex_t mutid=PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;
void* thread1(void *data)
{
	while(1)
	{
	pthread_mutex_lock(&mutid);
	pthread_mutex_lock(&mutid);
	count++;
	printf("Inc count %d",count);
	printf("add%d",add);
	pthread_mutex_unlock(&mutid);
	pthread_mutex_unlock(&mutid);
	}
}
void* thread2(void *data)
{
	while(1)
	{
	pthread_mutex_lock(&mutid);
	pthread_mutex_lock(&mutid);
	count--;
	printf("Dec count %d",count);
	pthread_mutex_unlock(&mutid); 
	pthread_mutex_unlock(&mutid);
	}
}
int main()
{
	pthread_t pid1,pid2;
	//pthread_mutex_init(&mutid,0);
	pthread_create(&pid1,NULL,thread1,NULL);
	pthread_create(&pid2,NULL,thread2,NULL);
	pthread_join(pid1,NULL);
	pthread_join(pid2,NULL);
}


