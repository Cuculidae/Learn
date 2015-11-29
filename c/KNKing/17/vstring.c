/**
 * C99 -- flexible array member (struct hack) 
 * Compilation: gcc -o vstring vstring.c -std=c99
 * Created: 2015-08-31
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures with flexible array members (or unions whose last member is a
// structure with flexible array member) cannot appear as array elements or as
// members of other structures.
struct vstring {
    int len;
    char chars[];   /* flexible array member - C99 only */
};

int main(void)
{
    // initialization, sizeof and assignment ignores flexible array member
    struct vstring a = {5};
    printf("sizeof a = %lu\n", sizeof(a));

    //  If no additional storage was allocated, it behaves as if an array with 1
    //  element, except that the behavior is undefined if that element is
    //  accessed or a pointer one past that element is produced.
    a.chars[0] = 'a';
    printf("a.chars[0] = %c\n", a.chars[0]);

    printf("sizeof(struct vstring) = %lu\n", sizeof(struct vstring));

    struct vstring *p;
    p = malloc(sizeof(struct vstring) + 10);
    strcpy(p->chars, "abcdef");
    printf("%s\n", p->chars);

    free(p);

    return 0;
}
