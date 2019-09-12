#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <ctype.h>

#define BUFFER BUFSIZ
#define MAXARGS 40


struct cmd {
	int argc;
	char cmd_name[BUFFER];
	char argv[MAXARGS][BUFFER];
};

void scan_input(struct cmd *cmd, char *input) {
	// Scanning for command
	int i;
	for(i = 0; i < strlen(input); i++) {
		if(!isspace(input[i])) cmd->cmd_name[i] = input[i];
		else {
			cmd->cmd_name[i++] = '\0';
			break;
		}
	}

	// Scanning for arguments
	int j = 0, li = i;
	for(; i < strlen(input); i++) {
		if(!isspace(input[i])) cmd->argv[j][i-li] = input[i];
		else {
			cmd->argv[j][i-li] = '\0';
			j++;


			li = i + 1;
		}
	}

	cmd->argc = j;
}

int main() {
	int pid;
	char *input = malloc(sizeof(char) * BUFFER);
	for (;;) {
		input = fgets(input, BUFFER, stdin);
        struct cmd cmd;

        scan_input(&cmd, input);

        if (strcmp(cmd.cmd_name, "q") == 0)
            break;

        char *args[MAXARGS+1] = { [0] = cmd.cmd_name };
        int i;

        for (i = 1; i <= cmd.argc; i++) {
            args[i] = cmd.argv[i-1];
        }

        args[i] = NULL;

	    if((pid = fork()) == 0) {
		    if(execv(cmd.cmd_name, args) == -1) {
                printf("Error\n");
                exit(1);
            }
        }
	}
	free(input);
	return 0;       
}
