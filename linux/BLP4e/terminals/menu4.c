/**
 * menu4.c
 * menu routine, version 4, using /dev/tty to provide better control over the
 * output.
 * Compilation: gcc -o menu4 menu4.c
 * Created: 2015-11-18
 */

#include <unistd.h> 
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>

/*
 * If you need to prevent the parts of your program that interact with the user
 * from being redirected, but still allow it to happen to other input or output,
 * you need to separate the interaction from stdout and stderr. You can do this
 * by reading and writing diretly to the terminal.
 * Linux and Unix make things easy by providing a special device, /dev/tty,
 * which is always the current terminal, or login session. Because Linux treats
 * everything as file, you can use normal file operations to read and write to
 * /dev/tty.
 */

char *menu[] = {
    "a - add new record",
    "d - delete record",
    "q - quit",
    NULL,
};

// you can pass FILE stream parameters to getchoice to get better constrol over
// the output
int getchoice(char *greet, char *choices[], FILE *in, FILE *out);

int main()
{
    int choice = 0;
    FILE *input;
    FILE *output;
    struct termios initial_settings, new_settings;

    // test whether stdout is connected to a terminal and halt execution if it isn't.
    if (!isatty(fileno(stdout))) {
        fprintf(stderr, "You are not a termila, OK\n");
    }
    
    input = fopen("/dev/tty", "r");
    output = fopen("/dev/tty", "w");
    if (!input || !output)  {
        fprintf(stderr, "Unable to open /dev/tty\n");
        exit(1);
    }
    // change the terminal's characteristics before calling getchoice
    tcgetattr(fileno(input), &initial_settings);
    new_settings = initial_settings;
    new_settings.c_lflag &= ~ICANON;
    new_settings.c_lflag &= ~ECHO;
    new_settings.c_cc[VMIN] = 1;
    new_settings.c_cc[VTIME] = 0;
    new_settings.c_lflag &= ~ISIG;
    if (tcsetattr(fileno(input), TCSANOW, &new_settings) != 0) {
        fprintf(stderr, "could not set attributes\n");
    }

    do {
        choice = getchoice("Please select an action", menu, input, output);
        printf("You have chosen: %c\n", choice);
    } while (choice != 'q');
    // return the settings to their original values before exiting
    tcsetattr(fileno(input), TCSANOW, &initial_settings);

    exit(0);
}

// you need to check against carriage returns now that you're in non-canonical
// mode, because the mapping of CR to LF is no longer being performed
int getchoice(char *greet, char *choices[], FILE *in, FILE *out)
{
    int chosen = 0;
    int selected;
    char **option;

    do {
        fprintf(out, "Choice: %s\n", greet);
        option = choices;
        while (*option) {
            fprintf(out, "%s\n", *option);
            option++;
        }
        // ingnore additional line feed character
        do {
            selected = fgetc(in);
        } while (selected == '\n' || selected == '\r');
        option = choices;
        while (*option) {
            if (selected == *option[0]) {
                chosen = 1;
                break;
            }
            option++;
        }
        if (!chosen) {
            fprintf(out, "Incorrect choice, select again\n");
        }
    } while (!chosen);
    return selected;
}
