// csapp: exercise 2.12
// Simulate Digital Equipment VAX instruction:
// bis (bit set), bic (bit clear)

#include "show_bytes.h"

/* Bit set */
int bis(int x, int m)
{
	int result = x | m;
	return result;
}

/* Bit clear */
int bic(int x, int m)
{
	int result = x & ~m;
	return result;
}

/* Compute x|y using only calls to functions bis and bic */
int bool_or(int x, int y)
{
	int result = bis(x, y);
	return result;
}

/* Compute x^y using only calls to functions bist and bic */
int bool_xor(int x, int y)
{
	int result = bis(bic(x, y), bic(y, x));
	return result;
}

int main()
{
	int mask = 0xFF;
	int x = 0xFFFF;
	show_int(bis(x, mask));
	show_int(bic(x, mask));
	
	byte i = 0xAA, j = 0x66;
	show_bits(i);
	show_bits(j);
	show_bits(i|j);
	show_bits(bool_or(i, j));
	show_bits(i^j);
	show_bits(bool_xor(i, j));

	return 0;
}

