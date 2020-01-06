#include<stdio.h>
#include<pthread.h>
#include <semaphore.h>
sem_t semid,semid2;

void * thread1(void *data)
{
	
}

void * thread1(void *data)
{
	
}

int main()
{
	pthread_t thd1,thd2;
	
	sem_init(&semid,0,1);
	sem_init(&semid1,0,0);
	pthread_create(&thd1,NULL,thread1,NULL);
	pthread_create(&thd2,NULL,thread2,NULL);
	
	pthread_join(thd1,NULL);
	pthread_join(thd2,NULL);
}
