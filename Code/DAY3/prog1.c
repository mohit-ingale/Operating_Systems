#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<stdlib.h>


int main(int argv,char *argc[])
{
  int fd,fd1,i,j=1024;
  char ch;
  printf("hello i am starting my program\n");
  printf("argc=%s\n",argc[1]);
  fd = open(argc[1],O_RDONLY);
  if(fd==-1)
    perror("error opening file\n");
  else
    printf("file opened sucessfully\n");
  fd1 = open(argc[2],O_CREAT|O_WRONLY,S_IRWXU|S_IRWXU);
  if(fd==-1)
    perror("error opening file\n");
  else
    printf("file opened sucessfully\n");
  while((i=read(fd,&ch,1)==1))
  {
    write(fd1,&ch,1);
  }
  close(fd);
  close(fd1);
}
