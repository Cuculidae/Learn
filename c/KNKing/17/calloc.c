#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    struct  point { int x, y; } *p;
    p = calloc(1, sizeof(struct point));
    printf("p->x = %d, p->y = %d\n", p->x, p->y);

    free(p);

    return 0;
}
