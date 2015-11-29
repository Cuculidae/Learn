/**
 * CS:APP (2ed) Chapter 8, 8.6
 * restart.c
 * Compilatioin: gcc -o restart restart.c
 * Created: 2015-08-29
 */

#include "csapp.h"

sigjmp_buf buf;

void handler(int sig)
{
    siglongjmp(buf, 1);
}

int main(void)
{
    Signal(SIGINT, handler);

    if (!sigsetjmp(buf, 1))
        printf("starting\n");
    else
        printf("restarting\n");

    while (1) {
        Sleep(1);
        printf("processing...\n");
    }
    exit(0);
}
