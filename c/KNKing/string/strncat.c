/**
 * Chapter 13 String
 * strncat.c
 * Compilation: gcc -o strncat strncat.c 
 * Created: 2015-08-24
 */

#include <stdio.h>
#include <stdlib.h>

#define LEN 20

size_t strlen(const char *s); 
char *strncat(char *s1, const char *s2, size_t n);
void print_char_array(char s[], size_t n);

int main(void)
{
    char s1[LEN+1];
    s1[0] = 'a'; s1[1] = 'b'; s1[2] = 'c'; s1[3] = '\0';
    strncat(s1, "defg", sizeof(s1) - strlen(s1) -1);
    print_char_array(s1, sizeof(s1));
    printf("\n");
    strncat(s1, "hijk", sizeof(s1) - strlen(s1) -1);
    print_char_array(s1, LEN+1);

    return 0;
}

char *strncat(char *s1, const char *s2, size_t n)
{
    char *p = s1;
    while (*p)
        ++p;
    while (n-- && (*p = *s2++))
        ++p;
    *p = '\0';
    return s1;
}

void print_char_array(char s[], size_t n)
{
    int i = 0;
    for (i = 0; i < n; ++i)
        if (s[i])   printf("'%c'  ", s[i]);
        else         printf("'\\0' ");
}

size_t strlen(const char *s)
{
    const char *p = s;

    while (*s)
        ++s;
    return s-p;
}
