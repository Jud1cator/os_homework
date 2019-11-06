#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFF_SIZE 20

int main() {
    char rs[BUFF_SIZE+1];
    rs[BUFF_SIZE] = '\0';
    int fd;
    if((fd = open("/dev/random", O_RDONLY)) == -1) { 
        printf("Can't open /dev/random\n"); 
        return 0; 
    }
    read(fd, rs, BUFF_SIZE);
    close(fd);

    for(int i = 0; i < BUFF_SIZE; i++) {
        // Storing only 94 readable charachters from ASCII (offset is 33)
        if(rs[i] < 0) rs[i] = -rs[i]%94+33;
        else rs[i] = rs[i]%94+33;
    }

    if((fd = open("ex1.txt", O_CREAT | O_RDWR, 0666)) == -1) { 
        printf("Can't open ex1.txt\n"); 
        return 0; 
    }
    write(fd, rs, BUFF_SIZE);
    close(fd);
    return 0;
}
