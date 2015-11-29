/**
 * Unit test the inplace_swap utilities.
 * Compilation: gcc -o test_inplace_swap test_inplace_swap.c
 */

#include <stdio.h>
#include "inplace_swap.h"

int main()
{
	int i = 1, j = 2;
	printf("Before inplace_iswap:\n");
	printf("i = %d, j = %d\n", i, j);
	printf("After inplace_iswap:\n");
	inplace_iswap(&i, &j);
	printf("i = %d, j = %d\n", i, j);

	int *ip = &i, *jp = &j;
	printf("Before inplace_pswap:\n");
	printf("ip = %p, jp = %p\n", ip, jp);
	printf("After inplace_pswap:\n");
	inplace_pswap((void *) &ip, (void *) &jp);
	printf("ip = %p, jp = %p\n", ip, jp);
	printf("*ip = %d, *jp = %d\n", *ip, *jp);

	return 0;
}
