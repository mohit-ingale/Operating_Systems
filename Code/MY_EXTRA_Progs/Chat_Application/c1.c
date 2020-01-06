#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#define MAX 1024
int main()
{
  char buff[]="hello";
  int ssock,chk;
  struct sockaddr_in saddr,caddr;
  socklen_t len;
  ssize_t cchk;
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
  chk=connect(ssock,(struct sockaddr *)&saddr,sizeof(saddr));
  if(-1==chk)
  {
    perror("Error in getting server\n");
    exit(EXIT_FAILURE);
  }
  /*chk=listen(ssock,16);
  if(-1==chk)
  {
    perror("Error in listening to client Address\n");
    exit(EXIT_FAILURE);
  }
  csock=accept(ssock,(struct sockaddr *)&caddr,&len);
  if(-1==csock)
  {
    perror("Error in opening socket\n");
    exit(EXIT_FAILURE);
  }*/
  cchk=recv(ssock,buff,MAX,0);
  puts(buff);
  if(-1==cchk)
  {
    perror("Error in receiving data\n");
    exit(EXIT_FAILURE);
  }
  puts("enter string");
  gets(buff);
  int lenn=strlen(buff);
  cchk=send(ssock,buff,lenn,MSG_CONFIRM);
  if(-1==cchk)
  {
    perror("Error in sending data\n");
    exit(EXIT_FAILURE);
  }

  
  chk=close(ssock);
  if(-1==chk)
  {
    perror("Error in closing server \n");
    exit(EXIT_FAILURE);
  }
}
