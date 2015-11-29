/**
 * CS:APP (2ed) Chapter 3,3.6.4
 * absdiff.c
 * Compilatiion: gcc -S absdiff.c
 * Created: 2015-08-16
 */

int absdiff(int x, int y)
{
    if (x < y)
        return y-x;
    else
        return x-y;
}
