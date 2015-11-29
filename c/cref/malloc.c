/**
 * malloc
 *      Defined in header <stdlib.h>
 *      void* malloc( size_t size );
 * Allocates <size> bytes of uninitialized storage.
 * If allocatino succeeds, returns a pointer to the lowest (frist) byte in the
 * allocated memeory block that is suitably aligned for any object type.
 * If size is zero, the behaviour is implementation defined (null pointer may be
 * returned, or some non-null pointer may be returned that may not be used to
 * access storage).
 * Paramenters
 *      size - number of bytes to allocate
 * Return value
 *      On success, return s the pointer to the beginning of newly allocated
 *      memory. The returned pointer must be deallocated with free() or
 *      realloc().
 *      On failure, returns a null pointer.
 * Note: (since C11)
 *      malloc is thread-safe: it behaves as though only accessing the memory
 *      locations visible through its argument, and not any static storage.
 *      A previous call to free or realloc that deallocates a region of memory
 *      synchronizes-with a call to malloc that allocates the same or a part of
 *      the same region of memory. This synchronization occurs after any access
 *      to the memeory by the deallocating function and before any access to the
 *      memory by malloc. There is a single total order of all allocation and
 *      deallocationi functions operating on each particular region of memory.
 * Compilation:
 *      gcc -o malloc malloc.c -std=c99
 * Created@:
 *      2015-08-03
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *p1 = malloc(4*sizeof(int));    // allocates enough for an array of 4 int
    int *p2 = malloc(sizeof(int[4]));   // same, naming the type directly
    int *p3 = malloc(4*sizeof(*p3));    // same, without repeating the type name

    if (p1) {
        for (int n = 0; n < 4; ++n) // populate the array
            p1[n] = n*n;
        for (int n = 0; n < 4; ++n) // print it back out
            printf("p1[%d] == %d\n", n, p1[n]);
    }

    free(p1);
    free(p2);
    free(p3);
}
