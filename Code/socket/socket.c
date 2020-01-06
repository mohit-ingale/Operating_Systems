#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>

#define MAX 255

int ssock,csock;
struct sockaddr_in saddr,caddr;
socklen_t len;
char buff[MAX];

int main(int argc, char const *argv[])
{
        int chk;

        saddr.sin_family=AF_INET;
        saddr.sin_port=htons(5695);
        chk=inet_pton(AF_INET,"127.0.0.1",&saddr.sin_addr);
        if(chk<0)
        {
                perror("error getting address\n");
                exit(EXIT_FAILURE);
        }

        ssock=socket(AF_INET,SOCK_STREAM,0);
        if(ssock==-1)
        {
                perror("Error Getting socket file descripto\n");
                exit(EXIT_FAILURE);
        }

        chk=bind(ssock,(struct sockaddr *)&saddr,sizeof(saddr));
        if(chk==-1)
        {
                perror("error binding address\n");
                exit(EXIT_FAILURE);
        }

        chk=listen(ssock,5);
        if(chk==-1)
        {
                perror("error listening\n");
                exit(EXIT_FAILURE);
        }

        csock=accept(ssock,(struct sockaddr *)&caddr,&len);
        if(csock==-1)
        {
                perror("error accepting\n");
                exit(EXIT_FAILURE);
        }

        recv(csock,buff,MAX,0);
        puts(buff);

        send(csock,"hello",5,MSG_CONFIRM);

        shutdown(csock,SHUT_RDWR);
        return 0;
}

