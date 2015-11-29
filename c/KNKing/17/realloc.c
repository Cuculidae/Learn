#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, n, *p;

    printf("Enter array size: ");
    scanf("%d", &n);

    p = malloc(n * sizeof(*p));
    
    for (i = 0; i < n; ++i)
        p[i] = i;
    for (i = 0; i < n; ++i)
        printf("%d ", p[i]);
    printf("\n");

    n = n / 2;

    p = realloc(p, n * sizeof(*p));
    for (i = 0; i < n; ++i)
        printf("%d ", p[i]);

    free(p);

    return 0;
}
