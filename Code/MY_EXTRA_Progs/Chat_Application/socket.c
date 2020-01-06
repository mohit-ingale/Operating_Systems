#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>
#define MAX 1024

char buff[MAX];
pthread_t thd[16];
int i=0,k=0;
int ssock,csock[10],chk,id;
struct sockaddr_in saddr,caddr;
socklen_t len;
ssize_t cchk;

/*
void * thread1(void *data)
{

  while(1)
{
  puts("enter data to send");
  gets(buff);
  int lp=strlen(buff);
    cchk=send(csock,buff,lp,MSG_CONFIRM);
    if(-1==cchk)
    {
      perror("Error in sending data\n");
      exit(EXIT_FAILURE);
    }
    cchk=recv(csock,buff,MAX,0);
    puts(buff);
    if(-1==cchk)
    {
      perror("Error in sending data\n");
      exit(EXIT_FAILURE);
    }
  }

}
*/

int main()
{
        int j;

  memset(buff,0,sizeof(buff));
  memset(&caddr,0,sizeof(caddr));
  memset(&saddr,0,sizeof(saddr));
  /*initialization of structure to use it over ipv4*/
  saddr.sin_family=AF_INET;
  chk=inet_pton(AF_INET,"127.0.0.1", &saddr.sin_addr);
  if(chk<0)
  {
    perror("Error in getting Address\n");
    exit(EXIT_FAILURE);
  }
  saddr.sin_port=htons(9000);
  ssock=socket(AF_INET,SOCK_STREAM,0);
  if(-1==ssock)
  {
    perror("Error in opening socket\n");
    exit(EXIT_FAILURE);
  }
  chk=bind(ssock,(struct sockaddr *)&saddr,sizeof(saddr));
  if(-1==chk)
  {
    perror("Error in getting Address\n");
    exit(EXIT_FAILURE);
  }
//pthread_create(&thd[j],NULL,thread1,NULL);
 chk=listen(ssock,3);
    if(-1==chk)
    {
      perror("Error in listening to client Address\n");
      exit(EXIT_FAILURE);
    }
  while(1)
  {

    //else
    {
      csock[i]=accept(ssock,(struct sockaddr *)&caddr,&len);
      if(-1==csock[i])
      {
        perror("Error in opening socket\n");
        exit(EXIT_FAILURE);
      }
      k=i++;
      //pthread_create(&thd[i++],NULL,thread1,NULL);
      id=fork();
      if(id==0)
      {
      	//char buff1[MAX];
       // while(1)
      {
      //  puts("enter data to send");
      //  gets(buff);
      //  int lp=strlen(buff);
        /*  cchk=send(csock,buff,lp,MSG_CONFIRM);
          if(-1==cchk)
          {
            perror("Error in sending data\n");
            exit(EXIT_FAILURE);
          }*/
          printf("Receiving data from thread %d\n",i);
          cchk=recv(csock[k],buff,MAX,0);
          puts(buff);
          if(-1==cchk)
          {
            perror("Error in receving data\n");
            exit(EXIT_FAILURE);
          }
                //puts("enter data to send");
                //gets(buff);
                /*int lp=strlen(buff);
                cchk=send(csock[i],buff,lp,MSG_CONFIRM);
                if(-1==cchk)
                {
                        perror("Error in sending data\n");
                        exit(EXIT_FAILURE);
                }*/

        }

      }
      for(j=0;j<=i;j++)
      {
              int lp=strlen(buff);
              cchk=send(csock[j],buff,lp,MSG_CONFIRM);
              if(-1==cchk)
              {
                      perror("Error in sending data\n");
                      exit(EXIT_FAILURE);
              }
      }
      chk=-1;
    }
}





  chk =close(csock[i]);
  if(-1==chk)
  {
    perror("Error in closing client \n");
    exit(EXIT_FAILURE);
  }
  chk=close(ssock);
  if(-1==chk)
  {
    perror("Error in closing server \n");
    exit(EXIT_FAILURE);
  }
}
