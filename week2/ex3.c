#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int n = atoi(argv[1]);
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j < n - i; j++) putchar(' ');
		for(int j = 0; j < 2*i-1; j++) putchar('*');
		putchar('\n');
	}
	return 0;
}
