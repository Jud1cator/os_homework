#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
    char *addr1, *addr2, *fname1 = "ex1.txt", *fname2 = "ex1.memcpy.txt";
    int fd1, fd2;
    struct stat sb;

    if((fd1 = open(fname1, O_RDWR)) == -1) exit(1);
    if((fd2 = open(fname2, O_CREAT|O_RDWR)) == -1) exit(2);
    if(fstat(fd1, &sb) == -1) exit(3);

    if(ftruncate(fd2, sb.st_size) == -1) exit(4);
    
    if((addr1 = mmap(NULL, sb.st_size, PROT_READ, MAP_SHARED, fd1, 0)) == MAP_FAILED) exit(5);

    if((addr2 = mmap(NULL, sb.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, fd2, 0)) == MAP_FAILED) exit(6);

    memcpy(addr2, addr1, sb.st_size);

    munmap(addr1, sb.st_size);
    munmap(addr2, sb.st_size);

    close(fd1);
    close(fd2);

    return 0;
}
