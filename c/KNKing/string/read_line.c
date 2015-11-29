/**
 * Chapter 13 String
 * read_line.c
 * Compilation: gcc -o read_line read_line.c
 * Created: 2015-08-24
 */

#include <stdio.h>

#define LEN 20

int read_line(char str[], int n);

int main(void)
{
    char str[LEN+1];
    printf("Enter a string:\n");
    read_line(str, LEN);
    printf("%s\n", str);

    return 0;
}

int read_line(char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n') // drop the '\n'
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';  // terminates string
    return i;       // number of characters stored
}
