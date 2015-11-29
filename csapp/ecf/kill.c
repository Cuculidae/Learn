/**
 * CS:APP (2ed) Chapter 8, 8.5.2
 * kill.c
 * Compilation: gcc -o kill kill.c
 * Created: 2015-08-25
 */

#include "csapp.h"

int main(void)
{
    pid_t pid;

    // child sleeps until SIGKILL signal received, the dies
    if ((pid = Fork()) == 0) {
        Pause(); // wait for a signal jto arrive
        printf("control should never reach here!\n");
        exit(0);
    }

    // parent sends a SIGKILL signal to child 
    Kill(pid, SIGKILL);
    exit(0);
}
