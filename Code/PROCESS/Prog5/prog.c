#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int id;
	id=fork();
	if(0==id)
	{
		//sleep(1);
		printf("My name is Murtaza Jafri\nRoll no - 28\nBirthdate - 11th August 1993\n");
	}	
	else
	{
		printf("My name is Mohit Mohan Ingale\nRoll no - 27\nBirthdate - 5th June 1995\n");
	}
	wait(NULL);
}
