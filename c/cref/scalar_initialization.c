/**
 * Scalar initialization
 * When initializing an object of {scalar type}, the initializer must be a 
 * single expression.
 * The initializer for a scalar (an object of integer type including booleans
 * and enumerated types, floating type including complex and imaginary, and
 * pionter type including pointer to function) must be a single expression,
 * optionally enclosed in braces:
 * Syntax:
 *      = expression        (1)
 *      = { expression }    (2)
 *      The expression is evaluated, and its value, after {conversion} as if 
 *      by {assignment} to the type of the object, becomes the initial value of
 *      the object being initialized.
 * Notes:
 *      Because of the rules that apply to conversions as if by assignment,
 *      const and volatile qualifiers on the declared type are ignored when
 *      determining which type to convert the <expression> to.
 *      See {initialization} for the rules that apply when no initializer is
 *      used.
 *      As with alll other initializations, <expression> must be a {constant
 *      exprssion} when initializing objects of static or thread_local storage
 *      duration.
 *      The <expression> cannot be a comma operator (unless parenthesized)
 *      because the comma at the top level would be interpreted as the
 *      beginning of the next declarator.
 *      When initializing objects of floating-point type, all computations for
 *      the objects with automatic storage duration are done as-if at execution
 *      time and are affeted by the {current rounding}; floating-point errors
 *      are reported as specified in {math_errhandling}. For objects of static
 *      and thread_local storage duration, computations are done as-if at
 *      compile time, and no exceptions are raised.
 * Compilation:
 *      gcc scalar_initialization.c -std=c99
 * Created@:
 *      2015-08-03
 */

void f(void)
{
#pragma STDC FENV_ACCESS ON
    static float v = 1.1e75;    // dose not raise exceptions: static init

    float u[] = { 1.1e75 }; // raises FE_INEXACT
    float w = 1.1e75;       // raises FE_INEXACT

    double x = 1.1e75;  // may raise FE_INEXACT (depends on FLT_EVAL_METHOD)
    float y = 1.1e75f;  // may raise FE_INEXACT (depends on FLT_EVAL_METHOD)

    long double z = 1.1e75; // dose not raise exceptions (conversion is exact)
}

#include <stdbool.h>    // since C99
int main()
{
    bool b = true;
    const double d = 3.14;
    int k = 3.15; // conversion from double to int
    int n = {12},   // optional braces
        *p = &n,    // non-constant expression OK for automatic variable
        (*fp)(void) = main;
    enum {RED, BLUE} e = RED;   // enumerations are scalar types as well
}

