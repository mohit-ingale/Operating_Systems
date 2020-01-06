#include<stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include<stdlib.h>
int main(int argc, char const *argv[]) {
    int sid,*addr,a;
	sid=shmget((key_t)1234,1,0666|IPC_CREAT);
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
  a=*addr;
  //  a=atoi(argv[argc-1]);
  a=a/2;
  *addr=a;
  printf("half pid=%d\n",getpid());

  printf("Half=%d\n",a);
  execv(argv[1],argv+1);
  }
