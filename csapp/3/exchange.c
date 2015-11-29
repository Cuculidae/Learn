/**
 * CS:APP   Chapter 3, 3.4.3
 * exchange.c
 * Dependencies:    none
 * Compilatio:      gcc -S exchange.c
 * Created:         2015-08-09
 */

int exchange(int *xp, int y)
{
    int x = *xp;
    *xp = y;
    return x;
}
