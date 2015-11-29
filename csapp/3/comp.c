/**
 * CS:APP (2ed) Chapter 3, 3.6.2
 * exercise 3.13
 * comp.c
 * Compilation: gcc -S -DCOMP=<COMP-OP> -Ddata_t=<TYPE> comp.c
 * Created: 2015-08-16
 */

int comp(data_t a, data_t b) {
    return a COMP b;
}
