/**
 * tmpnam.c
 * Compilation: gcc -o tmpnam tmpnam.c
 * Created: 2015-11-20
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * -----------------------------------------------------------------------------
 *  #include <stdio.h>
 *  char *tmpnam(char *s);
 * -----------------------------------------------------------------------------
 *  The tmpnam function returns a valid filename that isn't the same as any
 *  existing file. If the string s isn't null, the filename will also be written
 *  for it. Further calls to tmpnam will overwrite the static storage used for
 *  return values, so it's essential to use a string parameter if tmpnam is to
 *  be called many times. The string is assumed to be at least L_tmpnam
 *  characters long. tmpnam can be called up to TMP_MAX times in a single
 *  program, and it will generate a different filename each time.
 *
 *  If the temporary file is to be used immediately, you can name it and open it
 *  at the same time  using the tmpfile function.
 * -----------------------------------------------------------------------------
 *  #include <stdio.h>
 *  FILE *tmpfile(void);
 * -----------------------------------------------------------------------------
 *  The tmpfile function returns a stream pointer that refers to a unique
 *  temporary file. The file is opened for reading and writing, and it will be
 *  automatically deleted when all references to the file are closed.
 *  tmpfile returns a null pointer and sets errno on error.
 *
 *
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
 */

int main()
{
    char tmpname[L_tmpnam];
    char *filename;
    FILE *tmpfp;

    filename = tmpnam(tmpname);

    printf("Temporary file name is: %s\n", filename);
    tmpfp = tmpfile();
    if (tmpfp) 
        printf("Opened a temporary file OK\n");
    else
        perror("tmpfile");

    exit(0);
}
