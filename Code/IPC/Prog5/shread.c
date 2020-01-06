#include<stdio.h>
#include<stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include<unistd.h>

#define MAX 8
int main()
{

	int sid,size,*addr;
	char buff[20];
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
	
	printf("Message from sh mem : %d\n", *addr);	
	return 0;
}
