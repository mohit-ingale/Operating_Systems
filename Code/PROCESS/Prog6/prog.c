#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
	int id,fd[2];
	id=vfork();
	char buffer[100];
	pipe(fd);
	if(0==id)
	{
		//sleep(1);
		printf("My name is Murtaza Jafri\nRoll no - 28\nBirthdate - 11th August 1993\n");
		execl("pipe4","pipe4",buffer,NULL);
	}
	else
	{
		printf("My name is Mohit Mohan Ingale\nRoll no - 27\nBirthdate - 5th June 1995\n");
	}
}
