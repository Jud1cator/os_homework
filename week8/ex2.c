#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main() {
    for(int i = 0; i < 10; i++) {
        void *p;
        p = malloc(10*1024*1024);
        p = memset(p, 0, 10*1024*1024);
        sleep(1);
    }
    return 0;
}