/**
 * CS:APP (2ed) Chapter 7 Linking
 * 7.6.2
 * main2.c
 * Compilation: gcc -static -o p2 main2.c ./libvector.a
 * Created: 2015-08-20
 */

#include <stdio.h>
#include "vector.h"

int x[2] = {1, 2};
int y[2] = {3, 4};
int z[2];

int main()
{
    addvec(x, y, z, 2);
    printf("z = [%d %d]\n", z[0], z[1]);
    return 0;
}
