#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
char *s, c;
int n = 0;
do {
	c = getchar();
	n++;
	s = realloc(s, n * sizeof(char));
	s[n-1] = c;
} while(c != '\n');
for(int i = strlen(s)-1; i >= 0; i--)
{
	printf("%c", s[i]);
}
return 0;
}
