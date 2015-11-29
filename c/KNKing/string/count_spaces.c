/**
 * Chapter 13 String
 * count_spaces.c
 * Compilation: gcc -o count_spaces count_spaces.c
 * Created: 2015-08-24
 */

#include <stdio.h>

#define LEN 20

int count_spaces(const char s[]);

int main(void)
{
    char str[LEN+1];
    printf("Enter a string\n");
    gets(str);
    printf("num of spaces: %d", count_spaces(str));

    return 0;
}

int count_spaces(const char s[])
{
    int count = 0;

    for (; *s != '\0'; ++s)
        if (*s == ' ')
            ++count;
    return count;
}
