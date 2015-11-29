/**
 * free 
 *      Defined in header <stdlib.h>
 *      void free( void *ptr);
 * Deallocates the space previously allocated by malloc(), calloc(),
 * aligned_alloc,(since C11) or realloc().
 * If <ptr> is a null pointer, the function does nothing.
 * The behaviour is undefined if the value of <ptr> does not equal a value
 * returned earlier by malloc(), calloc(), realloc(), or alinged_alloc()(since
 * c11).
 * The behaviour is undefined if the memory area referred to by <ptr> has 
 * already been deallocated, that is, free() or realloc() has already been 
 * called with <ptr> as the argument and no calls to malloc(), calloc() or
 * realloc() resulted in a pointer equal to ptr afterwards.
 * The behaviour is undefined if after free() returns, an access is made
 * throught the pointer <ptr> (unless another allocation function happened to
 * result in a pointer value equal to ptr)
 * Paramenters
 *      ptr - pointer to the memory to deallocate
 * Return value
 *      (none)
 * Note: (since C11)
 *      free is thread-safe: it behaves as though only accessing the memory
 *      locations visible through its argument, and not any static storage.
 *      A previous call to free that deallocates a region of memory
 *      synchronizes-with a call to any subsequent allocation function that
 *      allocates the same or a part of the same region of memory. This 
 *      synchronization occurs after any access to the memeory by the 
 *      deallocating function and before any access to the memory by malloc. 
 *      There is a single total order of all allocation and deallocation 
 *      functions operating on each particular region of memory.
 *
 *      The function accepts (and does nothing with) the null pointer to reduce
 *      the amount of special-casing. Whether allocation succeeds or not, the
 *      pointer returned by an allocation function can be passed to free()
 * Compilation:
 *      gcc -o free free.c -std=c99
 * Created@:
 *      2015-08-03
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *p1 = malloc(10*sizeof(*p1));
    free(p1); // every allocated pointer must be freed

    int *p2 = calloc(10, sizeof *p2);
    int *p3 = realloc(p2, 1000* sizeof(*p3));
    if (p3) // p3 not null means p2 was freed by realloc
        free(p3);
    else    // p3 null means p2 was not freed
        free(p2);
}
