/**
 * gmtime.c
 * Prints out the current time and date using the tm structure and gmtime.
 * Compilation: gcc -o gmtime gmtime.c
 * Created: 2015-11-20
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*
 * To present the time and date in more meaningful way (to humans), you need to
 * convert time value into a recognizable time and date.
 * -----------------------------------------------------------------------------
 *  #include <time.h>
 *  struct tm *gmtime(const time_t *timeval);
 * -----------------------------------------------------------------------------
 *  The function gmtime breaks down a low-level time value into a structure
 *  containing more usual fields.
 *  gmtime returns the time as the GMT (now known as Coordinated Universal time,
 *  or UTC).
 *  The structure tm is defined to contain at least the following members:
 * -----------------------------------------------------------------------------
 *  int tm_sec      Seconds, 0-61
 *  int tm_min      Minutes, 0-59
 *  int tm_hour     Hours,  0-23
 *  int tm_mday     Day in the month, 1-31
 *  int tm_mon      Month in the year, 0-11 (January=0)
 *  int tm_year     Years since 1900
 *  int tm_wday     Day in the week, 0-6 (Sunday=0)
 *  int tm_yday     Day in the year, 0-365
 *  int tm_isdst    Daylight savings in effect
 * -----------------------------------------------------------------------------
 *  The range for tm_sec allows for the ocassional leap second or double leap
 *  second.
 */

int main()
{
    struct tm *tm_ptr;
    time_t the_time;

    (void) time(&the_time);
    tm_ptr = gmtime(&the_time);

    printf("Raw time is %ld\n", the_time);
    printf("gmtime gives:\n");
    printf("date: %02d/%02d/%02d\n",
            tm_ptr->tm_year, tm_ptr->tm_mon+1, tm_ptr->tm_mday);
    printf("time: %02d:%02d:%02d\n",
            tm_ptr->tm_hour, tm_ptr->tm_min, tm_ptr->tm_sec);

    exit(0);
}
