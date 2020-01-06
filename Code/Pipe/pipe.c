#include<stdio.h>q
#include<unistd.h>
#include<stdlib.h>
int main(int argc, char const *argv[]) {
pid_t id;
char buff[1024];
int fd[2];
pipe(fd);
id=fork();
if(id==0)
{
  printf("This Is Child\n");
  close(fd[1]);
  read(fd[0],buff,1024);
  printf("%s\n",buff);
}
else
{
  printf("this is Parent continued\n");
  //buff="hello child";
  scanf("%s",buff);
  write(fd[1],buff,1024);
}

  return 0;
}
