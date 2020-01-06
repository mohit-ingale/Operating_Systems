#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include <unistd.h>
#include<stdlib.h>
#include <fcntl.h>           /* For O_* constants */
       #include <sys/stat.h>  

sem_t *s;
int main()
{
	int val;
	s=sem_open("hello",O_CREAT|O_RDWR,0666,1);
	
	sem_wait(s);
	
	printf("waiting\n");
	while(1);
}
