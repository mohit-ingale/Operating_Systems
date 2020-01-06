#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	pid_t id;
	id=vfork();
	if(id==0)
	{
		printf("Child\n");
		execl("/bin/ps","/bin/ps","-e",NULL);
			
	}
	else
	{
		printf("i am parent\n");
	}
	wait(NULL);
}

