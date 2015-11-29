/**
 * Chapter 9 Functions
 * sum_array.c
 * Compilation: gcc -o sum_array sum_array.c -std=c99
 * Created: 2015-08-17
 */

#include <stdio.h>

int sum_array(int n, int a[n]); // Since C99, VLA function parameter
int sum_array(int n, int a[*]); // same declaration
int sum_array(int n, int a[]);  // same declaration, but less readable
int sum_array(int, int [*]);    // same declaration without parameter names

int main(void)
{
    // Since C99, Compound literal
    int total = sum_array(5, (int []) { 1, 2, 3, 4, 5});
    printf("total = %d\n", total);
}

int sum_array(int n, int a[n])
{
    int i, sum = 0;

    for (i=0; i < n; ++i)
        sum += a[i];
    
    return sum;
}
