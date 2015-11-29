/* CSAPP: Chapter 2, 2.1.4
 * show_byte utilities.
 * Compilation: gcc -c show_bytes.c
 */

#include <stdio.h>
#include "show_bytes.h"

void show_bits(byte b)
{
	int i;
	printf(" ");
	for (i = 0; i < sizeof(byte)*8; ++i, b >>= 1)
		printf("%d", b & 0x01);
	printf("\n");
}

void show_bytes(byte_pointer start, int len)
{
	int i;
	for (i=0; i<len; ++i)
		printf(" %.2x", start[i]);
	printf("\n");
}

void show_int(int x)
{
	show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x)
{
	show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x)
{
	show_bytes((byte_pointer) &x, sizeof(void *));
}

void show_carray(char a[], int cnt)
{
	int i;
	for (i = 0; i < cnt; ++i)
		printf(" %c ", a[i]);
	printf("\n");
}

void show_iarray(int a[], int cnt)
{
	int i;
	for (i = 0; i < cnt; ++i)
		printf(" %d ", a[i]);
	printf("\n");
}

void show_sarray(char* a[], int cnt)
{
	int i;
	for (i = 0; i < cnt; ++i)
		printf(" %s\n", a[i]);
}
