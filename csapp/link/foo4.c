/**
 * CS:APP (2ed) Chapter 7 Linking
 * 7.6.1
 * foo4.c
 * Dependencies: bar4.c
 * Compilation: gcc -o foobar4 foo4.c bar4.c
 * Created: 2015-08-20
 */

#include <stdio.h>
void f(void);

int x;

int main(void)
{
    x = 15213;
    f();
    printf("x = %d\n", x);
    return 0;
}
