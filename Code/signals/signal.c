#include<stdio.h>
#include <signal.h>
#include<string.h>
#include<unistd.h>
void sighandler(int signum,siginfo_t info)
{
  printf("you think i am interrupt no!!!\n i am signal from linux\n");
}

int main(int argc, char const *argv[]) {
  struct sigaction sa;
  memset(&sa,0,sizeof(sa));
  sa.sa_sigaction=sighandler;
  sigaction(SIGUSR1,&sa,NULL);
  while(1)
  {
    printf("i am waiting for your signal\n");
    sleep(1);
  }

  return 0;
}
