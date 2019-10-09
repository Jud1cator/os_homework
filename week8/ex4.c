#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/time.h>

int main() {
    for(int i = 0; i < 10; i++) {
        void *p;
        p = malloc(1024*1024*10);
        memset(p, 0, 1024*1024*10);
	struct rusage usg;
	getrusage(RUSAGE_SELF, &usg);
	printf("maxrss - %ld\n", usg.ru_maxrss);
        sleep(1);
    }
    return 0;
}