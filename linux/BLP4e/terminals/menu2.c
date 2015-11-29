/**
 * menu2.c
 * menu routine, version 2, takes care of redirection.
 * Compilation: gcc -o menu2 menu2.c
 * Created: 2015-11-18
 */

#include <unistd.h> // for isatty
#include <stdio.h>
#include <stdlib.h>

/*
 * You can tell whether the standard output has been redirected by finding out
 * if the low-level file descriptor is associated with a terminal.
 * -----------------------------------------------------------------------------
 *  #include <unistd.h>
 *  int isatty(int fd);
 * -----------------------------------------------------------------------------
 *  The isatty system call returns 1 if the open file descriptor, fd, is
 *  connected to a terminal and 0 otherwise.
 */

char *menu[] = {
    "a - add new record",
    "d - delete record",
    "q - quit",
    NULL,
};

int getchoice(char *greet, char *choices[]);

int main()
{
    int choice = 0;

    // test whether stdout is connected to a terminal and halt execution if it isn't.
    if (!isatty(fileno(stdout))) {
        fprintf(stderr, "You are not a termila!\n");
        exit(1);
    }
    
    do {
        choice = getchoice("Please select an action", menu);
        printf("You have chosen: %c\n", choice);
    } while (choice != 'q');

    exit(0);
}

int getchoice(char *greet, char *choices[])
{
    int chosen = 0;
    int selected;
    char **option;

    do {
        printf("Choice: %s\n", greet);
        option = choices;
        while (*option) {
            printf("%s\n", *option);
            option++;
        }
        // ingnore additional line feed character
        do {
            selected = getchar();
        } while (selected == '\n');
        option = choices;
        while (*option) {
            if (selected == *option[0]) {
                chosen = 1;
                break;
            }
            option++;
        }
        if (!chosen) {
            printf("Incorrect choice, select again\n");
        }
    } while (!chosen);
    return selected;
}
