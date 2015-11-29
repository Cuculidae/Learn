/**
 * Chapter 9 Functions
 * exercise 6
 * digit.c
 * Compilation: gcc -o digit digit.c
 * Created: 2015-08-19
 */

#include <stdio.h>

int digit(unsigned n, int k); // return the k-th digit of n

int main(void)
{
    unsigned u;
    int k;

    printf("Enter positive integer and position: ");
    scanf("%u%d", &u, &k);
    
    printf("the %dth digit of %u is %d\n", u, k, digit(u, k));

    return 0;
}

int digit(unsigned n, int k)
{
    int i;
    for (i=1; i < k; ++i)
        n /= 10U;

    // if k > number of digits in n
    // return 0
    return n % 10;
}
