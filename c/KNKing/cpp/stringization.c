/**
 * Chapter 14 Preprocessor
 *
 * Compilation: gcc -E stringization.c
 * Created: 2015-08-25
 */

// # operator used in function-like macros
// before an macro parameter

/* #define test(x) #a  // Error: # not used before macro parameter */

#define test(x) #x

test("contains quote and backslash \ ")     // escape surrounding " and inside /

test(1space 2space  3space   4space    end) // multiple spaces collapsed to single space

#define PRINT_INT(n) printf(#n " = %d\n", n)

PRINT_INT(i/j);
