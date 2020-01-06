#include <pthread.h>
#include <stdio.h>
#include <sched.h>
#define NUMBEROFTHREADS 5

void *thread1(void *param)
{
    printf("thread1 start\n");    
    sleep(1);
    printf("Thread 1 Ends\n");
    pthread_exit(0);    
}

void *thread2(void *param)
{
    printf("thread2 start\n");
    sleep(5);
    printf("Thread 2 ends\n");
    pthread_exit(0);
}

void *thread3(void *param)
{
    printf("thread3 start\n");
    sleep(1);
    printf("Thread 3 ends\n");
    pthread_exit(0);
}

void *thread4(void *param)
{
    printf("thread4 start\n");
    sleep(1);
    printf("Thread 4 ends \n");    
    pthread_exit(0);
}

void *thread5(void *param)
{
    printf("thread5 start\n");
    sleep(1);
    printf("Thread 5 ends\n");    
    pthread_exit(0);
}

int main(int argc, char *argv[])
{
    printf("**********************************\n");
    printf("Welcome to the Round Robin Example\n");
    printf("**********************************\n");
struct sched_param schedule_value;
schedule_value.sched_priority = 3;

int max , min ;


max = sched_get_priority_max(SCHED_OTHER);
min = sched_get_priority_min(SCHED_OTHER);

printf("max %d min %d",max,min);
    /*Creating all of the threads*/
    pthread_t tid[NUMBEROFTHREADS];
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);
   // pthread_attr_setschedpolicy(&attr, SCHED_FIFO);
	pthread_attr_setschedparam(&attr,&schedule_value);
    pthread_attr_setschedpolicy(&attr, SCHED_RR);
    pthread_create(&tid[0], &attr, &thread1, NULL);
    pthread_join(tid[0], NULL);

    pthread_create(&tid[1], &attr, &thread2, NULL);
    pthread_join(tid[1], NULL);

    pthread_create(&tid[2], &attr, &thread3, NULL);
    pthread_join(tid[2], NULL);

    pthread_create(&tid[3], &attr, &thread4, NULL);
    pthread_join(tid[3], NULL);

    pthread_create(&tid[4], &attr, &thread5, NULL);
    pthread_join(tid[4], NULL);    
    
    
}
