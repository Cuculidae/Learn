/**
 * CS:APP (2ed) Chapter 8, 8.4.3
 * waitpid2.c
 * Compilation: gcc -o waitpid2 waitpid2.c csapp.o
 * Created: 2015-08-25
 */

#include "csapp.h"

#define N 2

int main(void)
{
    int status, i;
    pid_t pid[N+1], retpid;

    for (i = 0; i < N; ++i)
        if ((pid[i] = Fork()) == 0) // child
            exit(100+i);

    // parent waits for all of its children to terminate
    i = 0;
    while ((retpid = waitpid(pid[i++], &status, 0)) > 0) {
        if (WIFEXITED(status))
            printf("child %d terminated normally with exit status=%d\n",
                    retpid, WEXITSTATUS(status));
        else
            printf("child %d terminated abnormally\n", retpid);
    }
    if (errno != ECHILD)
        unix_error("waitpid error");

    exit(0);
}
