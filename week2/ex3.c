#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_r_triang(int n)
{
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j < i; j++) putchar('*');
		putchar('\n');
	}
}

void print_i_triang(int n)
{
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j < n - i; j++) putchar(' ');
		for(int j = 0; j < 2*i-1; j++) putchar('*');
		putchar('\n');
	}
}

void print_arrow(int n)
{
	for(int i = 1; i <= n / 2; i++)
	{
		for(int j = 0; j < i; j++) putchar('*');
		putchar('\n');
	}
	for(int i = n / 2 + 1; i > 0; i++)
	{
		for(int j = 0; j < i; j++) putchar('*');
		putchar('\n');
	}
}

void print_rect(int n, int m)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++) putchar('*');
		putchar('\n');
	}
}


int main(int argc, char *argv[])
{
	char *fig = argv[1];
	if(strcmp(fig, "right_triangle")) print_r_triang(atoi(argv[2]));
	else if(strcmp(fig, "triangle")) print_i_triang(atoi(argv[2]));
	else if(strcmp(fig, "arrow")) print_arrow(atoi(argv[2]));
	else if(strcmp(fig, "rectangle")) print_rect(atoi(argv[2]), atoi(argv[3]));
	else printf("Wrong figure name. Use one of those:\ntriangle right_triangle arrow rectangle");
	return 0;
}
