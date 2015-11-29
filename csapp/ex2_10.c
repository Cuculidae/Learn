// csapp: exercise 2.10
// In-place swap
// using property of <{0,1}, ^, &, I, 0, 1>

#include <stdio.h>
#include "show_bytes.h"
#include "inplace_swap.h"

int main()
{
	int x = 1, y = 2;
	printf("Before swap:\n");
	show_int(x);
	show_int(y);
	inplace_swap(&x, &y);
	printf("After swap:\n");
	show_int(x);
	show_int(y);
	return 0;
}
