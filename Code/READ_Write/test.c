#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
       #include <fcntl.h>
       #include<unistd.h>
       #include<errno.h>
       int main()
       {
       
       int fd,i;
       
       fd=open("test.txt",O_WRONLY);
       if(-1==fd)
       	perror("FIle not created");
       i=write(fd,"HELLO", 5);
       
       close(fd);
       return 0;
       }
