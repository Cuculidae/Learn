/**
 * mktemp.c
 * Compilation: gcc -o mktemp mktemp.c
 * Created: 2015-11-20
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * -----------------------------------------------------------------------------
 *  #include <stdlib.h>
 *  char *mktemp(char *template);
 *  int   mkstemp(char *template);
 * -----------------------------------------------------------------------------
 *  The mktemp function creates a unique filename from the given template. The
 *  template argument must be a string with six trailing X characters. The
 *  mktemp function replaces these X characters with a unique combination of
 *  valid filename characters. It returns a pointer to the generated string or a
 *  null pointer if it couldn't generate a unique name.
 *
 *  The mkstemp function is similar to tmpfile in that is creates and opens a
 *  temporary file. The filename is generated in the same way as mkstemp, but
 *  the returned result is an open, low-level file descriptor.
 *
 * You should always use the "create and open" functions tmpfile and mkstemp in
 * your own programs rather than tmpname and mktemp.
 */

int main(int argc, char *argv[])
{
    if (argc == 1) {
        fprintf(stderr, "Usage: ./mktemp template\n");
        exit(1);
    }

    char *t = mktemp(argv[1]);
    printf("temporary filename: %s\n", t);
    printf("arg[1]: %s\n", argv[1]);

    exit(0);
}
