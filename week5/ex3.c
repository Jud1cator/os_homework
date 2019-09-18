#include <stdio.h>
#include <pthread.h>
#include <time.h>

#define BUFF_SIZE 100

volatile int count;

void sleep_prod() {
    while(count >= BUFF_SIZE);
}

void sleep_cons() {
    while(count == 0);
}

void *produce() {
    while(1) {
        if(count < BUFF_SIZE) {
            printf("Producing... count = %d\n", count);
            count++;
        } else sleep_prod();
    }
}

void *consume() {
    while(1) {
        if(count > 0) {
            printf("Consuming... count = %d\n", count);
            count--;
        } else sleep_cons();
    }
}

int main(void) {
    pthread_t producer, consumer;
    count = 0;
    pthread_create(&producer, NULL, produce, NULL);
    pthread_create(&consumer, NULL, consume, NULL);
    pthread_join(consumer, NULL);    
    return 0;
}

