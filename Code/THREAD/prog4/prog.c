#include<stdio.h>
#include<pthread.h>
#include <semaphore.h>
int count=0;
sem_t semid;

void * thread1(void *data)
{
	while(1)
	{
		sem_wait(&semid);
		count--;
		printf("dec count=%d\n",count);
		sem_post(&semid);
	}
}

int main()
{
	pthread_t thd;

	sem_init(&semid,0,1);
	pthread_create(&thd,NULL,thread1,NULL);
	while(1)
	{
		sem_wait(&semid);
		count++;
		printf("inc count=%d\n",count);
		sem_post(&semid);
	}
	pthread_join(thd,NULL);
}
