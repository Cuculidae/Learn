/**
 * CS:APP   Chapter 3, 3.4.3
 * exercise 3.2 decode1.c
 * Dependencies:    none
 * Compilation:     gcc -S decode1.c
 * Created:         2015-08-09
 */

void decode1(int *xp, int *yp, int *zp)
{
    int t = *xp;
    *xp = *yp;
    *yp = *zp;
    *zp = t;
}
