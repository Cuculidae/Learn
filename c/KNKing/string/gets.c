/**
 * Chapter 13 String
 * gets.c
 * Compilation: gcc -o gets gets.c
 * Created: 2015-08-24
 */

#include <stdio.h>

#define LEN 20

int main(void)
{
    char s[LEN+1];
    gets(s); // gets is not safe, may go out of bound
    printf("%s\n", s);
    
    return 0;
}
