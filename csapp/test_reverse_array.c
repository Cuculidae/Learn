/**
 * Unit test the reverse_array utilities.
 * Compilation: gcc -o test_reverse_array test_reverse_array.c reverse_array.o
 */

#include <stdio.h>
#include "reverse_array.h"
#include "show_bytes.h"

int main()
{
	int ia[] = {1, 2, 3, 4, 5};
	printf("Before reversing ia[]:\n");
	show_iarray(ia, (sizeof ia) / (sizeof ia[0]));
	printf("After reversing ia[]:\n");
	reverse_iarray(ia, (sizeof ia) / (sizeof ia[0]));
	show_iarray(ia, (sizeof ia) / (sizeof ia[0]));

	char* sa[] = {"123", "456", "789"};
	printf("Before reversing sa[]:\n");
	show_sarray(sa, (sizeof sa) / (sizeof sa[0]));
	printf("After reversing sa[]:\n");
	reverse_parray((void **) sa, (sizeof sa) / (sizeof sa[0]));
	show_sarray(sa, (sizeof sa) / (sizeof sa[0]));

	return 0;
}
