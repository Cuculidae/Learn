/* Testing the extern declaration */

#include <stdio.h>


extern int i;

int main(void)
{
    int j = 2;
    {
        j = 0;
        printf("i == %d\n", sizeof(i));
    }
    return 0;
}
