#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, n, *a;
    printf("Enter array size: ");
    scanf("%d", &n);
    a = malloc(n * sizeof(*a));
    
    for (i = 0; i < n; ++i) {
        a[i] = i;
        printf("%d ", a[i]);
    }

    free(a);

    return 0;
}
