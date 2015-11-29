/**
 * CS:APP (2ed) Chapter 7 Linking
 * 7.6.1
 * foo3.c
 * Dependencies: bar3.c
 * Compilation: gcc -o foobar3 foo3.c bar3.c
 * Created: 2015-08-20
 */

#include <stdio.h>
void f(void);

int x = 15213;

int main(void)
{
    f();
    printf("x = %d\n", x);
    return 0;
}
