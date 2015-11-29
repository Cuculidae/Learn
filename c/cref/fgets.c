/**
 * fgets
 *   Defined in header <stdio.h>
 * _____________________________________________________________________________
 *  char *fgets( cahr          *str, int count, FILE          *stream);  
 *                                                                 (Until C99)
 * _____________________________________________________________________________
 *  char *fgets( char *restrict str, int count, FILE *restrict stream );
 *                                                                 (Since C99)
 * _____________________________________________________________________________
 * Reads at most <count>-1 characters from the given file stream and stores them
 * in <str>. The produced character string is always null-terminated. Parsing
 * stops if end-of-file occurs or a newline character is found, in which case
 * <str> will contain that newline character
 *
 * Parameters
 *    str - string to read the characters to
 *  count - the length of str
 * stream - file stream to raed the data from
 *
 * Return value
 *  str on success, NULL on failure.
 *  If the failure has been caused by end-of-file condition, additionally sets
 *  the eof indicator (see feof()) on stream. If the failure has been caused by
 *  some other error, sets the error indicator (see ferror()) on stream.
 *
 * Compilation:
 *  gcc -o fgets fgets.c
 * Created:
 *  2015-08-10
 */


#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE* tmpf = tmpfile();
    fputs("Alan Turing\n", tmpf);
    fputs("John von Neumann\n", tmpf);
    fputs("Alonzo Church\n", tmpf);

    rewind(tmpf);

    char buf[8];
    while (fgets(buf, sizeof buf, tmpf) != NULL)
        printf("\"%s\"\n", buf);

    /* Test reason for reaching NULL. */
    if (feof(tmpf)) /* if failure caused by end-of-file condition */
        puts("End of file reached");
    else if (ferror(tmpf)) /* if failure caused by some other reason */
    {
        perror("fgets()");
        fprintf(stderr, "fgets() failed in file %s at line # %d\n",
                __FILE__, __LINE__-9);
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}
