/**
 * Chapter 9 Functions
 * Program Assignment 7
 * Compute power in logarithmic
 * power.c
 * Compilation: gcc -o power power.c
 * Created: 2015-08-19
 */

#include <stdio.h>

long long power(int x, int n);

int main(void)
{
    int x, n;

    printf("Enter number x and power n: ");
    scanf("%d%d", &x, &n);
    
    printf("%d to the power of %d is %lld", x, n, power(x, n));

    return 0;
}

long long power(int x, int n)
{
    if (n == 0) return 1;

    long long p = power(x, n>>1);

    if (n & 0x01)
        return x * p * p;
    else
        return p * p;
}
