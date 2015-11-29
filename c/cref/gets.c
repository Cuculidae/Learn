/**
 * gets, gets_s
 *   Defined in header <stdio.h>
 * _____________________________________________________________________________
 *  char *gets( char *str );                (until C11)
 * _____________________________________________________________________________
 *  char *gets_s( cahr *str, rsize_t n );   (since C11) (optional)
 * _____________________________________________________________________________
 *   1) Reads stdin into the charater array pointed by <str> until a newline
 *      character is found or end-of-file occurs. A null pointer is written
 *      immediately after the last character read into the array.
 *   2) Reads at most <n>-1 characters from stdin into the array pointed to by
 *      str until new-line character, end-of-file condition, or read error. A
 *      null character is written immediately after the last character read into
 *      the array, or to str[0] if no characters were read.
 *      If <n> is zero or greater than RSIZE_MAX, a null character is written to
 *      str[0] but the function reads and discards charactersw from stdin until
 *      new-line character, end-of-file condition or read error.
