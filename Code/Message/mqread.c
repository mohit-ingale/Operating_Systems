#include<stdio.h>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <mqueue.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1024
mqd_t msgq;
struct mq_attr attr;
int main(int argc, char const *argv[]) {
  memset(&attr,0,sizeof(attr));
  int msg_prio;
  char buff[MAX];
  attr.mq_flags=0;
  attr.mq_maxmsg=12;
  attr.mq_msgsize=1024;
  attr.mq_curmsgs=0;
  msgq=mq_open("/myqu1",O_CREAT|O_RDONLY,S_IRWXU,&attr);
  if((mqd_t)-1==msgq)
  {
    perror("error opening message queue\n");
    exit(EXIT_FAILURE);
  }
  else
  {
    printf("queue opened successfully\n");
  }
  if(mq_receive(msgq,buff,MAX,&msg_prio)==(size_t)-1)
  {
    perror("error receving message \n");
    exit(EXIT_FAILURE);
  }
  printf("the data received is %s",buff);
  return 0;
}
