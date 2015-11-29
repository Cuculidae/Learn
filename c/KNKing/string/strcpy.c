/**
 * Chapter 13 String
 * strcpy.c
 * Compilation: gcc -o strcpy strcpy.c
 * Created: 2015-08-24
 */

#include <stdio.h>

#define LEN 20

char *strcpy(char *s1, const char *s2);

int main(void)
{
    char s1[LEN+1] = "abc";
    strcpy(s1, "edf");
    strcpy(s1, "hij");
    printf("%s\n", s1);

    return 0;
}

char *strcpy(char *s1, const char *s2)
{
    while (*s1++ = *s2++)
        ;
    return s1;
}
