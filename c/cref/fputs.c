/**
 * fputs
 *   Defined in header <stdio.h>
 * _____________________________________________________________________________
 *  int fputs( const char          *str, FILE          *stream);    (until C99)
 * _____________________________________________________________________________
 *  int fputs( const char *restrict str, FILE *restrict stream);    (since C99)
 * _____________________________________________________________________________
 * Writes given null-terminated character string to be the given output stream.
 *
 * Parameters
 *    str - null-terminated character string to be written
 * stream - output stream
 *
 * Return value
 *  Non-negative integer on success, EOF on failure.
 *
 * Compilation:
 *  gcc -o fputs fputs.c
 * Created:
 *  2015-08-10
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int ret_code = fputs("Hello World\n", stdout);
    if ((ret_code == EOF) && (ferror(stdout))) /* test whether EOF was reached */
    {
        perror("fputs()");
        fprintf(stderr, "fputs() failed in file %s at line # %d\n",
                __FILE__, __LINE__-4);
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}
