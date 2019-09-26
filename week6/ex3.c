#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void sigkill_action() {
    printf("\nSIGKILL caught!\n");
    exit(0);
}

void sigstop_action() {
    printf("\nSIGSTOP caught!\n");
    exit(0);
}

void sigusr1_action() {
    printf("\nSIGUSR1 caught!\n");
    exit(0);
}

int main() {

    struct sigaction sint = {
        .sa_handler = sigint_action,
    };
    
    while(1) {
        sigaction(SIGINT, &sint, NULL);
    }
}
