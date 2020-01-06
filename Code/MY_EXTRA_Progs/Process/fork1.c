#include<stdio.h>
int main()
{
	int id;
	printf("Hello World\n");
	id=fork();
	if(id==0)
	{
		printf("this is child\n");
	}
	else
		printf("this is parent\n");
	return 0;
}

