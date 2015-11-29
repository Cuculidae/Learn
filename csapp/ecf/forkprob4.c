/**
 * CS:APP (2ed) Chapter 8, 8.4.2
 * forkprob4.c
 * Compilation: gcc -o forkprob4 forkprob4.c csapp.o
 * Created: 2015-08-25
 */

#include "csapp.h"

void doit()
{
    Fork();
    Fork();
    printf("hello\n");
    return;
}

int main(void)
{
    doit();
    printf("hello\n");
    exit(0);
}
