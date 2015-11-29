/**
 * CS:APP   Chapter 3, 3.5.4
 * arith.c
 * Dependencies:    none
 * Compilation:     gcc -S arith.c
 * Created:         2015-08-09
 */

int arith(int x, int y, int z)
{
    int t1 = x + y;
    int t2 = z * 48;
    int t3 = t1 & 0xFFFF;
    int t4 = t2 * t3;

    return t4;
}
