/**
 * ptrdiff_t
 *   Defined in header <stddef.h>
 *   typedef ..implementation-defined.. ptrdiff_t;
 * ptrdiff_t is the signed integer type of the result of subtracting two
 * pointers.
 * Notes:
 *  ptrdiff_t is used for pointers arithmetic and array indexing, if negative
 *  values are possible. Programs that use other types, such as int, may fail
 *  on, e.g. 64-bit systems when the index exceeds INT_MAx or if it relies on
 *  32-bit modular arithmetic.
 *  Only pointers to elements of the same array (including the pointer one past
 *  the end of the array) may be substracted from each other.
 *  If an array is so large (greater tha PTRDIFF_MAX elements, but less than
 *  SIZE_MAX bytes), that the differentce between two pointers may not be
 *  representable as ptrdiff_t, the result of subtracting two such pointers is
 *  undefined.
 *  For char arrays shorter than PTRDIFF_MAX, ptrdiff_t acts as the signed
 *  conterpart of size_t: it can store the size of the array of any type and is,
 *  on most platforms synonymous with intptr_t).
 * Compilation:
 *  gcc -o ptrdiff_t ptrdiff_t.c -std=c99
 * Created@:
 *  2015-08-06
 */

#include <stdio.h>
#include <stddef.h>
#include <stdint.h>

int main(void)
{
    const size_t N = 100;
    int numbers[N];

    printf("PTRDIFF_MAX = %ld\n", PTRDIFF_MAX);
    int *p1 = &numbers[18], *p2 = &numbers[23];
    ptrdiff_t diff = p2 - p1;
    printf("p2-p1 = %td\n", diff);

    return 0;
}
