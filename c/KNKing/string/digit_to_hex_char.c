/**
 * Chapter 13 String
 * digit_to_hex_char.c
 * Compilation: gcc -o digit_to_hex_char digit_to_hex_char.c
 * Created: 2015-08-24
 */

#include <stdio.h>

char digit_to_hex_char(int digit);

int main(void)
{
    int digit;
    printf("Enter a hex digit (0~15): ");
    scanf("%d", &digit);
    printf("Corresponding hex char: %c\n", digit_to_hex_char(digit));

    return 0;
}

char digit_to_hex_char(int digit)
{
    // string literal, there is a trailing '\0'
    return "0123456789ABCDEF"[digit];
}
