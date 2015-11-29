/**
 * Compilation: gcc -o qsort qsort.c
 * Created: 2015-08-31
 */

#include <stdio.h>
/* void qsort(void *base, size_t nmemb, size_t size,
 *            int (*compar) (const void *, const void *);
 */
#include <stdlib.h> 

#define N 10

int cmp(const void * a, const void * b)
{
    return *(int *) a - *(int *)b;
}

int main(void)
{
    int i;
    int a[N] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    qsort(a, N, sizeof(a[0]), cmp);
    for (i = 0; i < N; ++i)
        printf("%d ", a[i]);

    return 0;
}
