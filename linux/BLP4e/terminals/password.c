/**
 * password.c
 * Disabling of echo to read a password.
 * Compilation: gcc -o password password.c
 * Created: 2015-11-18
 */

#include <termios.h>
#include <stdio.h>
#include <stdlib.h>

#define PASSWORD_LEN 8

int main()
{
    struct termios initialrsettings, newrsettings;
    char password[PASSWORD_LEN + 1];

    // get the current settings from the standard input
    tcgetattr(fileno(stdin), &initialrsettings);

    // make a copy of the orignal settings, turn off the ECHO flag and ask the
    // user for his password
    newrsettings = initialrsettings;
    newrsettings.c_lflag &= ~ECHO;
    printf("Enter password: ");

    // set the terminal attributes to newrsettings and read the password
    if (tcsetattr(fileno(stdin), TCSAFLUSH, &newrsettings) != 0) {
        fprintf(stderr, "Could not set attributes\n");
    }
    else {
        fgets(password, PASSWORD_LEN, stdin);
        tcsetattr(fileno(stdin), TCSANOW, &initialrsettings);
        fprintf(stdout, "\nYou entered %s\n", password);
    }

    exit(0);
}
