#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include<stdio.h>
int main(int argc, char const *argv[]) {
  int fd,chk,*addr;
  off_t offset, pa_offset;
  offset = 1;
  size_t length;
  length = 1;
  pa_offset = offset & ~(sysconf(_SC_PAGE_SIZE) - 1);
  fd = shm_open("shmem", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IWGRP | S_IRGRP | S_IWOTH | S_IROTH);
  if(fd<0)
  {
    perror("error creating id for shared memory\n");
    exit(EXIT_FAILURE);
  }
  chk=ftruncate(fd,1);
  if(chk<0)
  {
    perror("error creating shared memory\n");
    exit(EXIT_FAILURE);
  }
  addr=mmap(NULL,1,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
  if ((int *)addr == MAP_FAILED)
  {
    perror("error maping shared memory\n");
    exit(EXIT_FAILURE);
  }
//  *addr=56;
  printf("value at shared memory =%d\n",*addr);
  munmap(addr,1);
  shm_unlink("shmem");
  return 0;
}
