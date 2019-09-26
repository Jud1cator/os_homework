#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t cpid;
    if((cpid = fork()) == -1) {
        printf("Error creating a child process\n");
    }
        
    if(cpid == 0) {
        while(1) {
            printf("I'm alive\n");
            sleep(1);
        }
    } else {
        sleep(10);
        kill(cpid, SIGKILL);  
    }
    printf("Parent is still alive\n");
}
