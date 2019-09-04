#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *a, int n)
{
    int swapped;
    do
    {
        swapped = 0;
	for(int i = 1; i < n; i++)
	{
	    if(a[i-1] > a[i])
	    {
		int t = a[i];
		a[i] = a[i-1];
		a[i-1] = t;
		swapped = 1;
	    }
	}
    } while(swapped);
}

int main()
{
    int n = 10;
    int a[n];
    for(int i = 0; i < n; i++)
	a[i] = rand() % n + 1;
    bubble_sort(a, n);
    for(int i = 0; i < n; i++)
	printf("%d ", a[i]);
    return 0;
}
