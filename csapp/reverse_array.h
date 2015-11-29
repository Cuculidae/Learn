/**
 * csapp 2nd ed: chapter 2, 2.1.8
 * Header file for reverse_array.c
 * reverse an array using inplace_swap
 */

#ifndef REVERSE_ARRAY_H
#define REVERSE_ARRAY_H

void reverse_carray(char [], int cnt);
void reverse_iarray(int a[], int cnt);
void reverse_larray(long a[], int cnt);
void reverse_parray(void* a[], int cnt);

#endif
