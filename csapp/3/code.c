/**
 * CS:APP   Chapter 3, 3.2.2
 * code.c
 * Compilation: gcc -O2 -S code.c
 *              gcc -S -masm=intel code.c // intel format
 *              gcc -O2 -c code.c
 * Created:     2015-08-09
 */

int accum = 0;
int sum(int x, int y)
{
    int t = x + y;
    accum += t;
    return t;
}
