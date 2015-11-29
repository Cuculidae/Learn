/**
 * CS:APP (2ed) Chapter 7 Linking
 * 7.6.1
 * foo5.c
 * Dependencies: bar5.c
 * Compilation: gcc -o foobar5 foo5.c bar5.c
 * Created: 2015-08-20
 */

#include <stdio.h>
void f(void);

int x = 15213;
int y = 15212;

int main(void)
{
    f();
    printf("x = 0x%x y = 0x%x \n", x, y);
    return 0;
}
