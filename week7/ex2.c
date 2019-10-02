#include <stdio.h>
#include <stdlib.h>

int main() {
	int *array, N;
    scanf("%d", &N);
    array = (int *) malloc(sizeof(int) * N);
    for(int i = 0; i < N; i++) {
        array[i] = i;
        printf("%d ", array[i]);
    }
    printf("\n");
    free(array);
    return 0;
}
