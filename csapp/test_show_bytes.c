// csapp: 2.1.4
// To test the show_bytes.c utility
// compilation: gcc -o test_show_bytes show_bytes.o test_show_bytes.c

#include <stdio.h>
#include "show_bytes.h"

void test_show_bytes(int val)
{
	int ival = val;
	float fval = (float) ival;
	int *pval = &ival;
	show_int(ival);
	show_float(12345.0f);
	show_pointer(pval);
}

int main(void)
{
	int ia[] = {1, 2, 3, 4, 5};
	char* sa[] = {"123", "456", "789"};
	show_bits(0xff);
	test_show_bytes(12345);
	show_iarray(ia, (sizeof ia) / (sizeof ia[0]));
	show_sarray(sa, (sizeof sa) / (sizeof sa[0]));
	return 0;
}
