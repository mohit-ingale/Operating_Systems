#include<stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h>
#include<stdlib.h>
int main()
{
  int id,*addr,ad;
  ad=0;
  id=shmget((key_t)1234,sizeof(int),044|IPC_CREAT);
  //id=shm_open("shm",O_CREAT|O_RDWR,0666);
  if(id==-1)
  {
      perror("shared memory not created");
      exit(EXIT_FAILURE);
  }
  addr=shmat(id,(void *)0 ,0);
  if(addr== (int *)(-1))
  {
    printf("error attaching storage\n");
  //  exit(EXIT_FAILURE);
  }
  //*addr=5;
  printf("shared memory contains =%d\n",*addr);
  /*if(shmdt(addr)== (int *)(-1))
  {
    perror("error dealocating shared memory\n");
    exit(EXIT_FAILURE);
  }
  else
  {
    printf("memory deloacted succesfully\n");
  }*/
}
