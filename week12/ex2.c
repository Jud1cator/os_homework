#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define BUFF_SIZE 1024

int main(int argc, char **argv) 
{
    int fd;
    int append = 0;
    if(argc > 1 && strcmp(argv[1], "-a") == 0) append = 1;

    char **t_argv = argv+1+append;
    int files[argc-1-append];
    int *t_files = files;
    while(*t_argv) 
    {
        if ((fd = open(*t_argv, O_WRONLY | O_CREAT | (append ? O_APPEND : O_TRUNC),
                       DEFFILEMODE)) == -1)
        {
			printf("Can't open %s\n", *t_argv);
            return 0;
		}
        *t_files = fd;
        printf("%d ", *t_files);
        t_files++;
        t_argv++;
    }

    char buff[BUFF_SIZE];

    // Termination on empty input (just newline)    
    while(strcmp(buff, "\n")) 
    {
        fgets(buff, BUFF_SIZE, stdin);
        printf("%s", buff);
        
        for(int i = 0; i < argc-1-append; i++)
            write(files[i], buff, strlen(buff));

    }
    return 0;
}
