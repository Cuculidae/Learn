/**
 * va_arg
 * _____________________________________________________________________________
 *   Defined in header <stdarg.h>
 * _____________________________________________________________________________
 *  T va_arg( va_list ap, T);
 * _____________________________________________________________________________
 * The va_arg macro expands to an expression of type <T> that corresponds to the
 * next parameter from the {va_list} <ap>.
 * Prior to calling va_arg, <ap> must be initialized by call to either
 * {va_start} or {va_copy}, with no intervening call to {va_end}. Each
 * invocation of the va_arg macro modifies <ap> to point to the next variable
 * argument.
 * If va_arg is called when there are no more arguments in <ap>, or if the type
 * of the next argument in <ap> (after promotions) is not compatible with <T>,
 * the behavior is undefined, unless:
 *  * one type is a signed integer type, the other type is the corresponding
 *    unsigned integer type, and the value is representable in both types; or
 *  * one type is pointer to void and the other is a pointer to a character
 *    type.
 *
 * Parameters
 *  ap - an instance of the va_list type
 *   T - the type of the next parameter in ap
 * Expanded value
 *  the next variable parameter in ap
 *
 * Compilation
 *  gcc -o va_arg va_arg.c
 * Created
 *  2015-08-13
 */

#include <stdio.h>
#include <stdarg.h>
#include <math.h>

double stddev(int count, ...)
{
    double sum = 0;
    double sum_sq = 0;
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; ++i) {
        double num = va_arg(args, double);
        sum += num;
        sum_sq += num*num;
    }
    va_end(args);
    return sqrt(sum_sq/count - (sum/count)*(sum/count));
}

int main(void)
{
    printf("%f\n", stddev(4, 25.0, 27.3, 26.9, 25.7));
}
