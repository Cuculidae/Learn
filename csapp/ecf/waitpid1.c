/**
 * CS:APP (2ed) Chapter 8, 8.4.3
 * waitpid1.c
 * Compilation: gcc -o waitpid waitpid.c csapp.o
 * Created: 2015-08-25
 */

#include "csapp.h"

#define N 2

int main(void)
{
    int status, i;
    pid_t pid;

    for (i = 0; i < N; ++i)
        if ((pid = Fork()) == 0) // child
            exit(100+i);

    // parent waits for all of its children to terminate
    while ((pid = waitpid(-1, &status, 0)) > 0) {
        if (WIFEXITED(status))
            printf("child %d terminated normally with exit status=%d\n",
                    pid, WEXITSTATUS(status));
        else
            printf("child %d terminated abnormally\n", pid);
    }
    if (errno != ECHILD)
        unix_error("waitpid error");

    exit(0);
}
