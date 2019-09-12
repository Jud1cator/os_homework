#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;
    if((pid = fork()) == 0)
	printf("Hello from child %d\n", getpid());
    else printf("Hello from parent %d\n", getpid());
    return 0;
}

