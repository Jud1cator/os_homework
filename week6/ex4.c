#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void sigkill_action() {
    printf("\nSIGKILL caught!\n");
}

void sigstop_action() {
    printf("\nSIGSTOP caught!\n");
}

void sigusr1_action() {
    printf("\nSIGUSR1 caught!\n");
}


int main() {

    struct sigaction susr1 = {
        .sa_handler = sigusr1_action,
    };

    struct sigaction skill = {
        .sa_handler = sigkill_action,
    };

    struct sigaction sstop = {
        .sa_handler = sigstop_action,
    };
    
    sigaction(SIGUSR1, &susr1, NULL);
    sigaction(SIGKILL, &skill, NULL);
    sigaction(SIGSTOP, &sstop, NULL);
    while(1);
}   
