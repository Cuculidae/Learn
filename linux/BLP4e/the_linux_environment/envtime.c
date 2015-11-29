/**
 * envtime.c
 */

#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*
 * Times are handled using a defined type, a time_t. This is an integer type
 * intended to be large enough to contain dates and times in seconds. On Linux
 * systems, it's a long integer and is defined, together with functions for
 * manupalating time values, in the header file <time.h>
 * -----------------------------------------------------------------------------
 *  #include <time.h>
 *  time_t time(time_t *tloc);
 * -----------------------------------------------------------------------------
 *  The time function returns the number of seconds since the start of the
 *  epoch. It will also write the returned value to a location pointed by loc,
 *  if this isn't a null pointer.
 *
 * The ISO/ANSI C standard committee didn't specify that the time_t type be used
 * to measure arbitrary time intervals in seconds, instead difftime is used.
 * -----------------------------------------------------------------------------
 *  #include <time.h>
 *  double difftime(time_t time1, time_t time2);
 * -----------------------------------------------------------------------------
 *  The difftime function calculates the difference between two time values and
 *  returns a value equivalent to time1-time2 as a floating-point number.
 */

int main()
{
    int i;
    time_t the_time;

    for (i = 1; i <= 10; ++i) {
        the_time = time(NULL);
        printf("The time is %ld\n", the_time);
        sleep(2);
    }

    exit(0);
}
