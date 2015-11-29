/**
 * Chapter 13 String
 * strcat.c
 * Compilation: gcc -o strcat strcat.c
 * Created: 2015-08-24
 */

#include <stdio.h>

#define LEN 20

char *strcat(char *s1, const char *s2);

int main(void)
{
    char s1[LEN+1] = "abc";
    strcat(s1, "edf");
    strcat(s1, "hij");
    printf("%s\n", s1);

    return 0;
}

char *strcat(char *s1, const char *s2)
{
    char *p = s1;
    while (*p)
        ++p;
    while (*p++ = *s2++)
        ;
    return s1;
}
