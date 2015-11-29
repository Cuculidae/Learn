/**
 * va_copy
 * _____________________________________________________________________________
 *   Defined in header <stdarg.h>
 * _____________________________________________________________________________
 *  void va_copy( va_list dest, va_list src );  (since C99)
 * _____________________________________________________________________________
 * The va_copy macro copies <src> to <dest>.
 * {va_end} should be called on <dest> before the function returns or any 
 * subsequent re-initialization of <dest> (via calls to {va_start} or 
 * {va_copy}).
 *
 * Parameters
 *  dest - an instance of the va_list type to initialize
 *   src - the source va_list that will be used to initialize dest
 *
 * Compilation
 *  gcc -o va_copy va_copy.c
 * Created
 *  2015-08-13
 */


#include <stdio.h>
#include <stdarg.h>
#include <math.h>

double sample_stddev(int count, ...)
{
    /* Compute the mean with args1. */
    double sum = 0;
    va_list args1;
    va_start(args1, count);
    va_list args2;
    va_copy(args2, args1); /* copy va_list object */
    for (int i = 0; i < count; ++i) {
        double num = va_arg(args1, double);
        sum += num;
    }
    va_end(args1);
    double mean = sum / count;

    /* Compute standard deviation with arg2 and mean */
    double sum_sq_diff = 0;
    for (int i = 0; i < count; ++i) {
        double num = va_arg(args2, double);
        sum_sq_diff += (num-mean)*(num-mean);
    }
    va_end(args2);
    return sqrt(sum_sq_diff / count);
}

int main(void)
{
    printf("%f\n", sample_stddev(4, 25.0, 27.3, 26.9, 25.7));
}
