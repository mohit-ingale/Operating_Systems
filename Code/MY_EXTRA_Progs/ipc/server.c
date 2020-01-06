#include<stdio.h>				//public will read from client and PRIVATE will write
#include <unistd.h>
#include <stdlib.h>	
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>	
#include<string.h>		
struct fifon{
	char PRIVATE[50];
	char cmd[10];
};
int main()
{
	struct fifon cli;
	FILE *fw;
	char buff[1000];
	int publicfifo,dummyfifo,client,n,count,done;
	mknod("PUBLIC", S_IFIFO | 0666,0);
	if((publicfifo=open("PUBLIC",O_RDONLY))==-1||(dummyfifo=open("PUBLIC",O_WRONLY)==-1))
	{
		perror("Error Opening public fifo\n");
		exit(1);
	}
	
	while((read(publicfifo,(char *)&cli,sizeof(cli)))>0)
	{
		count=done=0;
		do
		{
			if((client=open(cli.PRIVATE,O_WRONLY))==-1)
			{
				perror("Client not read\n");
				sleep(3);
			}
			else
			{
				
				fw=popen(cli.cmd,"r");
				memset(buff,0x0,sizeof buff);
				while((n=read(fileno(fw),buff,sizeof buff))>0)
				{
					//puts(buff);
					write(client,buff,n);
					memset(buff,0x0,sizeof buff);
				}
				pclose(fw);
				close(client);
				done=1;
			}
		}while(++count<5&&!done);
		if(!done)
		{
			write(2,"NO CLIENT\n",11);
		}
	}
}
