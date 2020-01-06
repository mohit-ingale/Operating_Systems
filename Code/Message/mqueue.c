#include<stdio.h>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <mqueue.h>
#include<stdlib.h>
mqd_t msgq;
struct mq_attr attr;
int main(int argc, char const *argv[]) {
  attr.mq_flags=0;
  attr.mq_maxmsg=12;
  attr.mq_msgsize=1024;
  attr.mq_curmsgs=0;

  msgq=mq_open("/myqu1",O_WRONLY|O_CREAT,S_IRWXU,&attr);
  if((mqd_t)-1==msgq)
  {
    perror("error opening message queue\n");
    exit(EXIT_FAILURE);
  }
  else
  {
    printf("queue created successfully\n");
  }
  mq_send(msgq,"hello\n",6,32767);
  return 0;
}
