#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
int main(int argc, char const *argv[]) {
  int id;
  printf("i am parent and id is %d\n",getpid());
  id=fork();
  if(0==id)
  {
    printf("child1=%d\n",getppid());
//    exit(EXIT_SUCCESS);
  }
  else
  {
    id=fork();
    if(0==id)
    {
      printf("child2=%d\n",getppid());
  //    exit(EXIT_SUCCESS);
    }
      wait(NULL);
  }
  return 0;
}
