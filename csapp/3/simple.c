/**
 * CS:APP   Chapter 3, 3.2.3
 * simple.c
 * Dependencies:    none
 * Compilation:     gcc -S simple.c
 * Created:         2015-08-09
 */

int simple(int *xp, int y)
{
    int t = *xp + y;
    *xp = t;
    return t;
}
