/**
 * Chatper 13 String
 * strcmp.c
 * Compilation: gcc -o strcmp strcmp.c
 * Created: 2015-08-24
 */

#include <stdio.h>

#define LEN 20

int strcmp(const char *s, const char *t);

int main(void)
{
    char s[LEN+1], t[LEN+1];
    printf("Enter a string: ");
    gets(s);
    printf("Enter a string: ");
    gets(t);

    int i = strcmp(s, t);
    if       (i > 0) printf("Larger\n");
    else if (i < 0) printf("Smaller\n");
    else             printf("Equal\n");

    return 0;
}

int strcmp(const char *s, const char *t)
{
    for (; *s && (*s == *t); ++s, ++t)
        ;
    return *s - *t;
}
