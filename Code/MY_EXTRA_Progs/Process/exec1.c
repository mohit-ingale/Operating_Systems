#include <unistd.h>
#include <stdio.h>
int main()
{
	int id;
	id=vfork();
	if(id==0)
	{
		execlp("/bin/ps", "/bin/ps",NULL);
		printf("done\n");
	}
	else
		printf("this is parent\n");
		join();
}
