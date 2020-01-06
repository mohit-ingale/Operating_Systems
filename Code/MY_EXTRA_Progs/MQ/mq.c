#include<stdio.h>
#include<mqueue.h>
#include <fcntl.h>
#include <sys/stat.h> 
int main()
{
	struct mq_attr attr;
	mqd_t id;
	id=mq_open("/mq1",O_CREAT|O_RDWR,0777,NULL);
	if(id==(mqd_t)-1)
	{
		perror("Error Creating Message Queue\n");
	}
	
	mq_getattr(id,&attr);
	printf("Max Msg are=%ld\n",attr.mq_maxmsg);
	printf("max msg size = %ld\n",attr.mq_msgsize);
}
