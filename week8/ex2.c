#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main() {
    for(int i = 0; i < 10; i++) {
        void *p;
        p = malloc(10240);
        p = memset(p, 0, 10240);
        sleep(1);
    }
    return 0;
}