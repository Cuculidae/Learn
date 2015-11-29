/**
 * CS:APP   Chapter 3, 3.5.3
 * exercise 3.5 shift_left2_rightn.c
 * Dependencies:    none
 * Compilation:     gcc -S shift_left2_rightn.c
 * Created:         2015-08-09
 */

int shift_left2_rightn(int x, int n)
{
    x <<= 2;
    x >>= n;
    return x;
}
