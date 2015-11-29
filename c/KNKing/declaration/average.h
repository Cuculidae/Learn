/**
 * Chapter 18 Declaration
 * average.h
 * Created: 2015-09-02
 */

#ifndef AVERAGE_H
#define AVERAGE_H

/*
 * Regardless of whether inlining takes place, the following semantics of inline
 * functions are guaranteed:
 * 1. Any function with internal linkage may be declared static inline with no
 *    other restrictions. 
 * 2. A non-static inline function cannot define a non-const function-local
 *    static and cannot refer to a file-scope static. 
 *
 * If a non-static function is declared inline, then it must be defined in the
 * same translation unit. The inline definition that does not use extern is not
 * externally visible and does not prevent other translation units from defining
 * the same function. This makes the inline keyword an alternative to static for
 * defining functions inside header files, which may be included in multiple
 * translation units of the same program.
 *
 * If a function is declared inline in some translation units, it does not need
 * to be declared inline everywhere: at most one translation unit may also
 * provide a regular, non-inline non-static function, or a function declared
 * extern inline. This one translation unit is said to provide the external
 * definition. 
 *
 * If the external definition exists in the program, the address of the function
 * is always the address of the external function, but when this address is used
 * to make a function call, it's unspecified whether the inline definition (if
 * present in the translation unit) or the external definition is called. The
 * static objects defined within an inline definition are distinct from the
 * static objects defined within the external definition: 
 */
inline double average(double a, double b)
{
    return (a+b) / 2;
}
