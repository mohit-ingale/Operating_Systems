#include<stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include<stdlib.h>
#include<stdlib.h>
int main()
{
  int id,id1;
  id=vfork();
  if(id==0)
  {
    id1=execl("/home/mohit_linux/Desktop/test/zombie","zombie",NULL);
    if(id1==-1)
    {
      perror("error in execl\n");
      exit(EXIT_SUCCESS);
    }
  }
  else{

  }
  wait(NULL);
}
