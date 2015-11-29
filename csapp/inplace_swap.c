/**
 * csapp: Chapter 2, 2.1.8 
 * swap two items inplace using property of <{0,1}, ^, &, I, 0, 1>
 * Compilation: gcc -c inplace_swap.c
 */

#include "inplace_swap.h"

void inplace_cswap(char *x, char *y)
{
	*x = *x ^ *y;
	*y = *x ^ *y;
	*x = *x ^ *y;
}

void inplace_iswap(int *x, int *y)
{
	*x = *x ^ *y;
	*y = *x ^ *y;
	*x = *x ^ *y;
}

void inplace_lswap(long *x, long *y)
{
	*x = *x ^ *y;
	*y = *x ^ *y;
	*x = *x ^ *y;
}

void inplace_pswap(void **x, void **y)
{
	*x = (void *) ((unsigned long long) *x ^ (unsigned long long) *y);
	*y = (void *) ((unsigned long long) *x ^ (unsigned long long) *y);
	*x = (void *) ((unsigned long long) *x ^ (unsigned long long) *y);
}
