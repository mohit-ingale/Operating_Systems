#include<stdio.h>
#include <unistd.h>
#include<stdlib.h>
int main()
{
  int id;
  id=vfork();
  if(id==0)
  {
      _exit(EXIT_SUCCESS);
  }
  else
  {
    sleep(4);
    printf("i am parent\n");
  }
}
