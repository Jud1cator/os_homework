#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/time.h>

void print_rusage()
{
    struct rusage usg;
    getrusage(RUSAGE_SELF, &usg);
    printf("rusage: ");
    printf("utime - %ld %ld ", usg.ru_utime.tv_sec, usg.ru_utime.tv_usec);
    printf("stime - %ld %ld ", usg.ru_stime.tv_sec, usg.ru_stime.tv_usec);
    printf("maxrss - %ld ", usg.ru_maxrss);
    printf("minflt - %ld ", usg.ru_minflt);
    printf("majflt - %ld ", usg.ru_majflt);
    printf("nvcsw - %ld ", usg.ru_nvcsw);
    printf("nivcsw - %ld ", usg.ru_nivcsw);
    printf("\n");
}

int main() {
    for(int i = 0; i < 10; i++) {
        void *p;
        p = malloc(10240);
        p = memset(p, 0, 10240);
        print_rusage();
        sleep(1);
    }
    return 0;
}