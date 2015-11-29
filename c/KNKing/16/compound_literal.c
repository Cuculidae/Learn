/**
 * Chapter 16 Struct, Union and Enum
 * compound_literal.c
 * Compilation: gcc -S compound_literal.c
 * Created: 2015-08-27
 */

#define NAME_LEN 20

void f(void)
{
    struct part {
        int number;
        char name[NAME_LEN+1];
        int on_hand;
    } part1;

    //part1 = (struct part) {528, "Disk drive", 10};
    part1 = (struct part) { .on_hand = 10,
                               .name = "Disk drive",
                               .number = 528};
}
