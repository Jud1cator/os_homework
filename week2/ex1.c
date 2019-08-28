#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
	int a;
	float b;
	double c;
	a = INT_MAX;
	b = FLT_MAX;
	c = DBL_MAX;
	printf("a: size: %lu value: %d\nb: size: %lu value: %f\nc: size: %lu value: %lf",
		sizeof(a), a, sizeof(b), b, sizeof(c), c);
	return 0;
}
