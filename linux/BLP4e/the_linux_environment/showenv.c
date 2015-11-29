/**
 * showenv.c
 * Use the environ variable to print out the environment variables.
 * Compilation: gcc -o showenv showenv.c
 * Created: 2015-11-17
 */


#include <stdlib.h>
#include <stdio.h>

/*
 *
 * -----------------------------------------------------------------------------
 *  #include <stdlib.h>
 *  extern char **environ;
 * -----------------------------------------------------------------------------
 *  As you've seen, the program environment is made up of strings of the form
 *  name=value. This array of strings is made available to the program directly
 *  via the environ variable.
 */

extern char **environ;

int main()
{
    char **env = environ;

    while (*env) {
        printf("%s\n", *env);
        env++;
    }

    exit(0);
}
