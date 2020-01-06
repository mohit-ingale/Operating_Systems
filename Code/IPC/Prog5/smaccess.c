#include<stdio.h>
#include<stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include<unistd.h>
#define MAX 1
int main()
{
	int sid,*addr;
	sid=shmget((key_t)1234,MAX,0666|IPC_CREAT);
	if(sid==-1)
	{
		perror("Error creating memory\n");
		exit(EXIT_FAILURE);
	}
	addr=shmat(sid,NULL,0);
	if((int *)addr==-1)
	{
		perror("Error attaching memory\n");
		exit(EXIT_FAILURE);
	}
	*addr=12;
	printf("Written on shared memory\n");
	//while(1);	
	return 0;
}
