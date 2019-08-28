#include <stdio.h>

void swap(int *a, int *b)
{
int t = *a;
*a = *b;
*b = t;
}

int main()
{
int a, b;
printf("Enter two numbers:");
scanf("%d %d", &a, &b);
swap(&a, &b);
return 0;
}
