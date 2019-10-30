#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{
    char s[5];

    memset(s, 0, 5);
        
    setvbuf(stdout, s, _IOLBF, 5);

    printf("H");
    sleep(1);
    printf("e");
    sleep(1);
    printf("l");
    sleep(1);
    printf("l");
    sleep(1);
    printf("o");
    sleep(1);
    printf("\n");

    //memset(s, 0, 6);

	return 0;
}	
