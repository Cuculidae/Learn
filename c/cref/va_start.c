/**
 * va_start
 * _____________________________________________________________________________
 *   Defined in header <stdarg.h>
 * _____________________________________________________________________________
 *  void va_start( va_list ap, parmN );
 * _____________________________________________________________________________
 * The va_start macro enables access to the variable arguments following the
 * named argument <parmN>. va_start should be invoked with an instance to a
 * valid {va_list} object <ap> before any calls to {va_arg}. If <parmN> is
 * declared with register storage  class specifier, with an array type, with
 * function type, or with type not compatible with the type that results from
 * default argument promotions, the behavior is undefined.
 * 
 * Parameters
 *     ap - an instance of the va_list type
 *  parmN - the named parameter preceding the first variable parameter
 *
 * Compilation
 *  gcc -o va_start va_start.c
 * Created
 *  2015-08-13
 */

#include <stdio.h>
#include <stdarg.h>

int add_nums(int count, ...)
{
    int result = 0;
    va_list args;
    va_start(args, count);
    for (int i=0; i < count; ++i) {
        result += va_arg(args, int);
    }
    va_end(args);
    return result;
}

int main(void)
{
    printf("%d\n", add_nums(4, 25, 25, 50, 50));
}
