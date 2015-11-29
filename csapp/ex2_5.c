// exercise 2.5
// compilation: gcc -o ex2_5 ex2_5.c show_bytes.o

#include "show_bytes.h"

int main(void)
{
	int val = 0x12345678;
	byte_pointer valp = (byte_pointer) &val;
	show_bytes(valp, 1);
	show_bytes(valp, 2);
	show_bytes(valp, 3);

	return 0;
}
