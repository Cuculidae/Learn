/**
 * sizeterm.c
 */

#include <stdio.h>
#include <curses.h>
#include <stdlib.h>

int main()
{
    int nrows, ncols;

    setupterm(NULL, fileno(stdout), NULL);
    nrows = tigetnum("lines");
    ncols = tigetnum("cols");
    printf("This terminal has %d columns and %d rows\n", ncols, nrows);

    exit(0);
}
