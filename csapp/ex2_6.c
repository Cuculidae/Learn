// exercise 2.6
// comilation: gcc -o ex2_6 ex2_6.c show_bytes.c

#include "show_bytes.h"

int main(void)
{
	int ival = 3490593;
	float fval = 3490593.0f;
	show_int(ival);
	show_float(fval);

	return  0;
}
