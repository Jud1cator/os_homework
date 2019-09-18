#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* thread_func (int *);

int main (int argc, char *argv[], char *envp[]) {
    int N;
    pthread_t thread;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        if (pthread_create(&thread, NULL, thread_func, (void *) &i)) return EXIT_FAILURE;
	printf("Thread number %d created\n", i+1);
        pthread_join(thread, NULL);        
    }
}

void* thread_func (int *N) {
    printf("Thread %d: I'm thread %d\n", *N+1, *N+1);
}
