/**
 * environ.c
 * Program to print out the value of any environment variable you chose. You
 * also arrange to set the value if you give the program a second argument.
 * Compilation: gcc -o environ environ.c
 * Created: 2015-11-17
 */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/*
 * -----------------------------------------------------------------------------
 *  #include <stdlib.h>
 *  char *getenv(const char *name);
 * -----------------------------------------------------------------------------
 *  The getenv function searches the environment for a string with the given
 *  name and returns the value associated with that name. It will return null if
 *  the requested variable doesn't exist. If the variable exists but has no
 *  value, getenv succeeds and returns an empty string, one in which the first
 *  byte is null. The string returned by getenv is held in static storage owned
 *  by getenv, so to use it further you must copy it to another string because
 *  it will be overwritten by subsequent calls to getenv.
 *
 * -----------------------------------------------------------------------------
 *  #include <stdlib.h>
 *  int putenv(const char *string);
 * -----------------------------------------------------------------------------
 *  The putenv function takes a string of the form name=value and adds it to the
 *  current environment. It will fail and return -1 if it can't extend the
 *  environment due to lack of available memory. When this happens, the error
 *  variable errno will be set to ENOMEM.
 */


/* Note that the environment is local only to the program. Changes that you make
 * within the program are not reflected outside it because variable values are
 * not propagated from the child process (you program) to the parent(the shell).
 */
int main(int argc, char* argv[])
{
    char *var, *value;

    // ensure the program has been called correctly with just one or two arguments
    if (argc == 1 || argc > 3) {
         fprintf(stderr, "usage: environ var [value]\n");
         exit(1);
    }

    // fetch the value of the variable from the environment using getenv
    var = argv[1];
    value = getenv(var);
    if (value)
        printf("Variable %s has value %s\n", var, value);
    else
        printf("Variable %s has no value\n", var);

    // check whether the program was called with a second argument
    // If it was, you set the variable to the value of that argument by
    // constructing a string of the form name=value and then calling putenv
    if (argc == 3) {
        char *string;
        value = argv[2];
        string = malloc(strlen(var) + strlen(value) + 2);
        if (!string) {
            fprintf(stderr, "out of memory\n");
            exit(1);
        }
        strcpy(string, var);
        strcat(string, "=");
        strcat(string, value);
        printf("Calling putenv with: %s\n", string);
        if (putenv(string) != 0) {
            fprintf(stderr, "putenv failed\n");
            free(string);
            exit(1);
        }

        // discover the new value of the variable by calling getenv once again
        value = getenv(var);
        if (value)
            printf("New value of %s is %s\n", var, value);
        else
            printf("New value of %s is null??\n", var);
    }

    exit(0);
}
