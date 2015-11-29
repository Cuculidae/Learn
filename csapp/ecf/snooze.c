/**
 * CS:APP (2ed) Chapter 8, 8.4.4
 * snooze.c
 * Compilation: gcc -o snooze snooze.c csapp.o
 * Created: 2015-08-25
 */

#include "csapp.h"

void handler(int sig)
{
    return;
}

unsigned int snooze(unsigned int secs)
{
    unsigned int rc = sleep(secs);
    printf("Slept for %u of %u secs\n",
            secs - rc, secs);
    return;
}

int main(int argc, char *argv[])
{
    if (argv[1] == NULL) {
        printf("Usage: snooze SECS\n");
        exit(0);
    }

    if (signal(SIGINT, handler) == SIG_ERR)
        unix_error("signal error");

    snooze(atoi(argv[1]));

    return 0;
}
