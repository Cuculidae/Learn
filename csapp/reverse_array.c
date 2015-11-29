/**
 * CSAPP 2nd edition: chapter 2, 2.1.8
 * Compilation: gcc -c reverse_array.h
 * Utilities for reversing an array using inplace_swap
 */

#include "inplace_swap.h"
#include "reverse_array.h"

void reverse_carray(char a[], int cnt) {
	int first, last;
	for (first = 0, last = cnt -1; first < last; ++first, --last)
		inplace_cswap(&a[first], &a[last]);
}

void reverse_iarray(int a[], int cnt) {
	int first, last;
	for (first = 0, last = cnt -1; first < last; ++first, --last)
		inplace_iswap(&a[first], &a[last]);
}

void reverse_larray(long a[], int cnt) {
	int first, last;
	for (first = 0, last = cnt -1; first < last; ++first, --last)
		inplace_lswap(&a[first], &a[last]);
}

void reverse_parray(void* a[], int cnt) {
	int first, last;
	for (first = 0, last = cnt -1; first < last; ++first, --last)
		inplace_pswap(&a[first], &a[last]);
}

