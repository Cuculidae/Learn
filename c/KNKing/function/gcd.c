/**
 * Chapter 9 Functions
 * exercise 3
 * Compute GCD of two integers
 * gcd.c
 * Compilation: gcc -o gcd gcd.c
 * Created: 2015-08-19
 */

#include <stdio.h>

int gcd(int m, int n);

int main(void)
{
    int m, n;

    printf("Enter two numbers: ");
    scanf("%d%d", &m, &n);
    
    printf("GCD of %d and %d is %d\n", m, n, gcd(m, n));

    return 0;
}

int gcd(int m, int n)
{
    if (n == 0) return m;

    return gcd(n, m % n);
}
