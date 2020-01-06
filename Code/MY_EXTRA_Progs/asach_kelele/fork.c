 #include<stdio.h>
 #include <unistd.h>
 #include <stdlib.h>
 int i = 6; 
 int main(void) 
 { 
 	int var; 
 	pid_t pid; 
 	var = 10; 
 	printf("Before calling fork"); 
 	if((pid = fork()) < 0) 
 		printf("fork error"); 
 	else if(pid == 0)
 		{ i++; var++; }
 	else 
 		sleep(2); 
 	printf("pid = %d,i=%d,var = %d ",getpid(),i,var); 
 	exit(0); 
 }
