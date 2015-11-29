/**
 * Chapter 9 Functions
 * exercise 4
 * day_of_year.c
 * Compilation: gcc -o day_of_year day_of_year.c
 * Created: 2015-08-19
 */

#include <stdio.h>
#include <stdbool.h>

/* is the year a leap year */
#define isLeap(year) (((year%4==0) && (year%100!=0)) || (year%400==0))

int day_of_year(int month, int day, int year);

int main(void)
{
    int m, d, y;
    printf("Enter month, day and year: ");
    scanf("%d%d%d", &m, &d, &y);
    
    printf("%d/%d/%d is the %dth day in year (%d days)\n",
            y, m, d, day_of_year(m, d, y), isLeap(y) ? 366 : 365);

    return 0;
}

/* return the ordinal of date in the year */
int day_of_year(int month, int day, int year)
{
    static int days[2][31] = {
        {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, },
        {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, },
    };

    bool isleap = isLeap(year);

    int cnt = 0;
    for (int m=0; m < month; ++m)
        cnt += days[isleap][m];
    
    return cnt + day;
}
