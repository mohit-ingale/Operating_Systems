#include<stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include<stdlib.h>
#include<string.h>
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
  //*addr=5;
  a=*addr;
  int i;
  //for(i=0;i<argc;i++)
  ////printf("%s\n",argv[i]);
  printf("add pid=%d\n",getpid());
a=a+a;
*addr=a;
printf("add=%d\n",a);
execv(argv[1],argv+1);

}
