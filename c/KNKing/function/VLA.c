/**
 */

#include <stdio.h>

int main(void)
{
    int size;
    printf("Enter the size of VLA: ");
    scanf("%d", &size);
    int a[size];
    // sizeof VLA is evaluated in runtime
    printf("sizeof VLA = %zu\n", sizeof(a));
}
