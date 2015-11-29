/**
 * CS:APP (2ed) Chapter 8, 8.5.4
 * signal1.c
 * Compilation: gcc -o signal1 signal1.c csapp.o
 * Created: 2015-08-25
 */

#include "csapp.h"

void handler1(int sig)
{
    pid_t pid;

    if ((pid = waitpid(-1, NULL, 0)) < 0)
        unix_error("waitpid error");
    printf("Handler reaped child %d\n", (int)pid);
    Sleep(2);
    return;
}

int main()
{
    int i, n;
    char buf[MAXBUF];

    if (signal(SIGCHLD, handler1) == SIG_ERR)
        unix_error("signal error");

    // parent created child
    for (i = 0; i < 3; ++i) {
        if (Fork() == 0) {
            printf("Hello from child %d\n", (int) getpid());
            Sleep(1);
            exit(0);
        }
    }

    // parent waits for terminal input and then processes it
    if ((n = read(STDIN_FILENO, buf, sizeof(buf))) < 0)
            unix_error("read");
    printf("Parent processing input\n");
    while (1)
        ;
    
    exit(0);
}
