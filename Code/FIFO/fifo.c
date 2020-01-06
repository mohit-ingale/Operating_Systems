#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
  FILE *fd;
  int id;
  fd=popen("jiko","r");
  if(NULL==fd)
  {
    perror("error opening file\n");
    exit(EXIT_FAILURE);
  }
  else
  {
    printf("pipe opened successfully\n");
  }
  id=pclose(fd);
  if(-1==id)
  {
    perror("unable to close file\n");
  }
  else
  {
    printf("file successfully closed\n");
  }
  //fputs("hello",fd);

}
