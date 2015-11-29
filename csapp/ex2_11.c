/**
 * csapp 2nd edition: chapter 2, 2.1.8
 * Utilities to reverse an array using inplace_swap 
 */

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

void reverse_farray(float a[], int cnt) {
	int first, last;
	for (first = 0, last = cnt -1; first < last; ++first, --last)
		inplace_fswap(&a[first], &a[last]);
}

void reverse_darray(double a[], int cnt) {
	int first, last;
	for (first = 0, last = cnt -1; first < last; ++first, --last)
		inplace_dswap(&a[first], &a[last]);
}

void reverse_parray(void *(a[]), int cnt) {
	int first, last;
	for (first = 0, last = cnt -1; first < last; ++first, --last)
		inplace_pswap(&a[first], &a[last]);
}

