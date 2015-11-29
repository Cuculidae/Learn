/**
 * CSAPP: Chapter 2, 2.2.5
 * Compilation: gcc -o ex2_21 ex2_21.c
 */

#include "show_bytes.c"

int fun1(unsigned word)
{
    return (int) ((word << 24) >> 24);
}

int fun2(unsigned word)
{
    return ((int) word << 24) >> 24;
}

int main()
{
    unsigned x = 127U;
    show_int(x);
    show_int(fun1(x));
    show_int(fun2(x));

    x = 128U;
    show_int(x);
    show_int(fun1(x));
    show_int(fun2(x));

    x = 255U;
    show_int(x);
    show_int(fun1(x));
    show_int(fun2(x));

    x = 256U;
    show_int(x);
    show_int(fun1(x));
    show_int(fun2(x));

}
