// exercise 2.7
// compilation: gcc -o ex2_7 ex2_7.c show_bytes.o

#include <string.h>
#include "show_bytes.h"

int main(void)
{
	char *s = "ABCDEF";
	show_bytes(s, strlen(s));

	return 0;
}
