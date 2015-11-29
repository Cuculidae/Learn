/**
 * Chapter 17 Advanced Pointer
 * concat.c
 * Compilation: gcc -o concat concat.c
 * Created: 2015-08-31
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concat(const char *s1, const char *s2);

int main(void)
{
    char *s = concat("abc", "def");
    printf("%s\n", s);

    free(s);

    return 0;
}

char *concat(const char *s1, const char *s2)
{
    char *result;

    result = malloc(strlen(s1) + strlen(s2) + 1);
    if (result == NULL) {
        printf("Error: malloc failed in concat\n");
        exit(EXIT_FAILURE);
    }
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}
