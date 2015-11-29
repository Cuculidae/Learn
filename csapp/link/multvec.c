/**
 * CS:APP (2ed) Chapter 7 Linking
 * 7.6.2
 * multvec.c
 * compose the libvector.a
 * Compilation: gcc -c multvec.c
 * Created: 2015-08-20
 */

void multvec(int *x, int *y, int *z, int n)
{
    int i;

    for (i = 0; i < n; ++i)
        z[i] = x[i] * y[i];
}
