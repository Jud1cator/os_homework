#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RES 3
#define PROC 5

int isgreq(int *a, int *b)
{
    int ret = 1;
    for(int i = 0; i < RES; i++)
        if(a[i] < b[i]) ret = 0;
    return ret;
}

void add(int *a, int *b)
{
    for(int i = 0; i < RES; i++)
        a[i] += b[i];
}

void sub(int *a, int *b)
{
    for(int i = 0; i < RES; i++)
        a[i] -= b[i];
}

void print(int *a, int l)
{
    for(int i = 0; i < l; i++)
        printf("%d ", a[i]);
    printf("\n");
}


int main(int argc, char **argv)
{
    FILE *input, *output;
    int E[RES], A[RES], C[PROC][RES], R[PROC][RES+1];
    
    if(argc != 2) 
    {
        printf("Enter filename as argument\n");
        return 0;
    }

    /*
     * Reading input  
     */
  
    
    if((input = fopen(argv[1], "r")) == NULL)
    {
        printf("Can't open %s\n", argv[1]);
        return 0;
    }

        for(int i = 0; i < RES; i++)
        fscanf(input, "%d ", &E[i]);

    for(int i = 0; i < RES; i++)
        fscanf(input, "%d ", &A[i]);

    for(int i = 0; i < PROC; i++)
    {
        for(int j = 0; j < RES; j++)
            fscanf(input, "%d ", &C[i][j]);
    }

    for(int i = 0; i < PROC; i++)
    {
        R[i][RES] = 1; // request is pending
        for(int j = 0; j < RES; j++)
            fscanf(input, "%d ", &R[i][j]);
    }

    fclose(input);

    /*
     * Algorithm
     */

    int dlock = 0, req_accepted = 1, in_progress = 0;

    for(;;)
    {
        if(req_accepted == 0)
        {
            dlock = in_progress;
            break;
        }
    
        req_accepted = 0;
        in_progress = 0;

    // Scanning through processes
        for(int i = 0; i < PROC; i++)
        {
            // If process' request is not accepted yet
            if(R[i][RES])
            { 
                in_progress = 1;
                // Check if we can accept it
                if(isgreq(A, R[i]))
                {
                    sub(A, R[i]);
                    add(A, C[i]);
                    memcpy(C[i], R[i], RES * sizeof(int));
                    R[i][RES] = 0;
                    req_accepted = 1;
                }
            }
        }
    }

    if(dlock == 1)
    {
        output = fopen("output_dl.txt", "w+");
        for(int i = 0; i < PROC; i++)
        {
            if(R[i][RES] == 1)
                fprintf(output, "%d\n", i+1);
        }
    }
    else
    {
        output = fopen("output_ok.txt", "w+");
        fprintf(output, "No deadlock is detected\n");
    }

    return 0;
}

