/**
 * ctime.c
 * Compilation: gcc -o ctime ctime.c
 * Created: 2015-11-20
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * -----------------------------------------------------------------------------
 *  #include <time.h>
 *  char *asctime(const struct tm *timeptr);
 *  char *ctime(const time_t *timeval);
 * -----------------------------------------------------------------------------
 *  The asctime function returns a string that represents the time and date
 *  given by the tm structure to which timeptr points. The string returned has a
 *  fixed format, 26 characters long.
 *
 *  The function ctime is equivalent to calling
 *   asctime(localtime(timeval))
 */

int main()
{
    time_t timeval;

    (void) time(&timeval);
    printf("The date is: %s\n", ctime(&timeval));

    exit(0);
}
