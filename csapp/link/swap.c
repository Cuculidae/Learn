/**
 * CS:APP (2ed) Chapter 7 Linking
 * 7.1 Compilaer Drivers
 * swap.c 
 * Dependecies: main.c
 * Created: 2015-08-20
 */

extern int buf[];

int *bufp0 = buf;
int *bufp1;

void swap()
{
    int temp;

    bufp1 = &buf[1];
    temp = *bufp0;
    *bufp0 = *bufp1;
    *bufp1 = temp;
}
