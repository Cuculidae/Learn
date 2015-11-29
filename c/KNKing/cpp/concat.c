/**
 * Chapter 14 Preprocessor
 *
 * Compilation: gcc -E concat.c
 * Created: 2015-08-25
 */

// ## only tokens that form a valid token together may be paseted
// this is called concatenation or token pasting
// A comment cannot be created by pasting / and * because comments
// are removed from text before macro substitution is consider
#define MK_ID(n) i##n

int MK_ID(1), MK_ID(2), MK_ID(3);


#define GENERIC_MAX(type) \
    type type##_max(type x, type y) \
    {                               \
        return x > y ? x : y;       \
    } 

GENERIC_MAX(float)

GENERIC_MAX(int)

// Beware!
#define CONCAT(a, b) a##b

CONCAT(a, CONCAT(b,c))
