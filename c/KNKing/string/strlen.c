/**
 * Chapter 13 String
 * strlen.c
 * Compilation: gcc -o strlen strlen.c
 * Created: 2015-08-24
 */

#include <stdio.h>
#include <stdlib.h>

#define LEN 20

size_t strlen(const char *s);

int main(void)
{
    char s[LEN+1];
    printf("Enter a string:\n");
    gets(s);
    printf("Length: %d\n", strlen(s));

    return 0;
}

size_t strlen(const char *s)
{
    const char *p = s;

    while (*s)
        ++s;
    return s-p;
}

