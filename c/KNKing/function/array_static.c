/**
 * Chapter 9 Functions
 * Demonstrate keyword static usage in function array parameter
 * array_static.c
 * Compilation: gcc -o array_static array_static.c -std=c99 
 * Created: 2015-08-17
 */

#include <stdio.h>

// a call to sum_array performs compile-time bounds checking
// and also permits optimization such as prefetching
// Don't cause compile-time error
int sum_array(int a[static 6], int n); // Since C99, 

int main(void)
{
    // Since C99, Compound literal
    int total = sum_array((int []) { 1, 2, 3, 4, 5}, 5);
    printf("total = %d\n", total);
}

int sum_array(int a[static 6], int n)
{
    int i, sum = 0;

    for (i=0; i < n; ++i)
        sum += a[i];
    
    return sum;
}
