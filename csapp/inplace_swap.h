/**
 * csapp: Chapter 2, 2.1.8 
 * swap two items inplace using property of <{0,1}, ^, &, I, 0, 1>
 */

#ifndef INPLACE_SWAP_H
#define INPLACE_SWAP_H

void inplace_cswap(char *x, char *y);
void inplace_iswap(int *x, int *y);
void inplace_lswap(long *x, long *y);
void inplace_pswap(void **x, void **y);

#endif
