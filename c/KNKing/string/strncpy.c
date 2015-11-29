/**
 * Chapter 13 String
 * strncpy.c
 * Compilation: gcc -o strncpy strncpy.c
 * Created: 2015-08-24
 */

#include <stdio.h>
#include <stdlib.h>

#define LEN 20

char *strncpy(char *s1, const char *s2, size_t n);
void print_char_array(char s[], size_t n);

int main(void)
{
    char s1[LEN+1]; 
    strncpy(s1, "abcdef", 3);
    print_char_array(s1, sizeof(s1));
    printf("\n");
    strncpy(s1, "abcdef", sizeof(s1)-1);
    s1[sizeof(s1)-1] = '\0';
    print_char_array(s1, LEN+1);

    return 0;
}

char *strncpy(char *s1, const char *s2, size_t n)
{
    while (n-- && (*s1++ = *s2++))
        ;
    while (n--) // fill '\0'
        *s1++ = '\0';
    return s1;
}

void print_char_array(char s[], size_t n)
{
    int i = 0;
    for (i = 0; i < n; ++i)
        if (s[i])   printf("'%c'  ", s[i]);
        else         printf("'\\0' ");
}
