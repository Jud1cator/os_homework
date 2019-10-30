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
    char *addr, *fname = "ex1.txt";
    int fd;
    struct stat sb;
    char *s = "This is a nice day";
    int len = strlen(s);

    if((fd = open(fname, O_RDWR)) == -1) exit(1);
    if(fstat(fd, &sb) == -1) exit(1);
    if(ftruncate(fd, len) == -1) exit(1);
    
    if((addr = mmap(NULL, sb.st_size, PROT_WRITE, MAP_SHARED, fd, 0)) == MAP_FAILED) exit(1);

    memcpy(addr, s, len);

    munmap(addr, sb.st_size);
    close(fd);

    return 0;
}	
