/**
 * CS:APP (2ed) Chapter 8, 8.4.2
 * forkprob1.c
 * Compilation: gcc -o forkprob1 forkprob1.c csapp.o
 * Created: 2015-08-25
 */

#include "csapp.h"

int main(void)
{
    int i;
    for (i = 0; i < 2; ++i)
        Fork();
    printf("hello!\n");
    exit(0);
}
