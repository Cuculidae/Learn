/**
 * CS:APP (2ed)  Chapter 3, 3.5.5
 * exercise 3.12 store_prod.c
 * Compilation: gcc -S store_prod.c
 * Created: 2015-08-12
 */

typedef long long num_t;
void store_prod(num_t *dest, unsigned x, num_t y)
{
    *dest = x*y;
}
