#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void sigstop() {
    printf("SIGSTOP received\n");
    exit(0);
}

int main() {
    pid_t cpid1, cpid2;
    int pipefd[2];

    printf("Parent: creating a pipe\n");
    if(pipe(pipefd) == -1) {
        printf("Error creating a pipe\n");
    }

    printf("Parent: creating 1st child\n");

    if((cpid1 = fork()) == -1) {
        printf("Error creating a child process\n");
    }

    if(cpid1 == 0) {
        pid_t t = -1;
        
        close(pipefd[1]);
        read(pipefd[0], &t, sizeof(pid_t));
        close(pipefd[0]);
        printf("Child 1: reading 2nd child's pid from a pipe - %d\n", t);
          
     
        
        printf("Child 1: c2 pid is %d\n", t);
        sleep(2);
        printf("Child 1: sending SIGSTOP to Child 2\n");
        kill(t, SIGSTOP);
    } 
    
    else {
        printf("Parent: creating 2nd child\n");
        if((cpid2 = fork()) == -1) {
            printf("Error creating a child process\n");
        }
        
        if(cpid2 == 0) {
            struct sigaction s;
            s.sa_handler = sigstop;
            sigaction(SIGSTOP, &s, NULL);

            while(1) {
                printf("Child 2: hello\n");
                sleep(1);
            }
        } 
        
        else {
            printf("Parent: writing 2nd child's pid into a pipe - %d\n", cpid2);
            write(pipefd[1], &cpid2, sizeof(pid_t));
            close(pipefd[1]);
	        int status;
            waitpid(cpid2, &status, 0);
            printf("Parent: child 2 changed state - status %d\n", status);
        }
        
    }
}
