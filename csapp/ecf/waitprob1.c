/**
 * CS:APP (2ed) Chapter 8, 8.4.4
 * waitprob1.c
 * Compilation: gcc -o waitprob1 waitprob1.c csapp.o
 * Created: 2015-08-25
 */

#include "csapp.h"

int main(void)
{
    int status;
    pid_t pid;

    printf("hello\n");
    pid = Fork();
    printf("%d\n", !pid);
    if (pid != 0) {
        if (waitpid(-1, &status, 0) > 0) {
            if (WIFEXITED(status) != 0)
                printf("%d\n", WEXITSTATUS(status));
        }
    }
    printf("Bye\n");
    exit(2);
}
