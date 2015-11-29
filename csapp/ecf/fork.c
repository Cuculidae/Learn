/**
 * CS:APP (2ed) Chapter 8, 8.4.2
 * fork.c
 * Compilation: gcc -o fork fork.c csapp.o
 * Created: 2015-08-25
 */

#include "csapp.h"

int main(void)
{
    pid_t pid;
    int x = 1;

    pid = Fork();
    if (pid == 0) { // child
        printf("child : x = %d\n", ++x);
        exit(0);
    }

    // parent
    printf("parent: x = %d\n", --x);
    exit(0);
}
