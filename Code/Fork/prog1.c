#include<stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char const *argv[]) {
  pid_t id;
  printf("this is parent\n");
  id=fork();
  if(0==id)
  {
    printf("this is a child process\n");
    exit(EXIT_SUCCESS);
  }
  else
  {
    printf("this is a parent process\n");
  }
  return 0;
}
