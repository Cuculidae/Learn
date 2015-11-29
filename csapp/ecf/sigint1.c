/**
 * CS:APP (2ed) Chapter 8, 8.5.3
 * sigint1.c
 * Compilation: gcc -o sigint1 sigint1.c csapp.o
 * Created: 2015-08-25
 */

#include "csapp.h"

void handler(int sig) // SIGINT handler
{
    printf("Caught SIGINT\n");
    exit(0);
}

int main(void)
{
    // install the SIGINT handler
    if (signal(SIGINT, handler) == SIG_ERR)
        unix_error("signal error");

    pause(); // wait for receipt of signal
    exit(0);
}
