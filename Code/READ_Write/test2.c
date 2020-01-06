#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
       #include <fcntl.h>
       #include<unistd.h>
       #include<errno.h>
       #define MAX 1024
       int main()
       {
       
       int fd,i;
       char buff[MAX];
       fd=open("test.txt",O_RDONLY);
       if(-1==fd)
       	perror("FIle not created");
       i=read(fd,buff,MAX);
       printf("\n%s\n",buff);
       close(fd);
       return 0;
       }
