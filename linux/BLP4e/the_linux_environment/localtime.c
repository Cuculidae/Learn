/**
 * localtime.c
 * Prints out the current date and time using localtime.
 * Compilatioin: gcc -o localtime localtime.c
 * Created: 2015-11-20
 */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * -----------------------------------------------------------------------------
 *  #include <time.h>
 *  struct tm *localtime(const time_t *timeval);
 * -----------------------------------------------------------------------------
 *  The localtime function is identical to gmtime, except that it returns a
 *  structure containing values adjusted for local time zone and daylight
 *  savings.
 *
 * -----------------------------------------------------------------------------
 *  #include <time.h>
 *  time_t mktime(struct tm *timeptr);
 * -----------------------------------------------------------------------------
 *  To convert a broken-down tm structure into a raw time_t value, you can use
 *  the function mktime. mktime will return -1 if the structure can't be
 *  represented as a time_t value.
 */

int main()
{
    struct tm *tm_ptr = NULL;
    time_t the_time;

    (void) time(&the_time);
    tm_ptr = localtime(&the_time);

    printf("Raw time is %ld\n", the_time);
    printf("localtime gives\n");
    printf("data: %02d/%02d/%02d\n",
            tm_ptr->tm_year, tm_ptr->tm_mon+1, tm_ptr->tm_mday);
    printf("time: %02d:%02d:%02d\n",
            tm_ptr->tm_hour, tm_ptr->tm_min, tm_ptr->tm_sec);

    exit(0);
}
