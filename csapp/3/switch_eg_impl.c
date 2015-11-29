/**
 * CS:APP (2ed) Chapter 3, 3.6.7
 * switch_eg_impl.c
 * Compilation: gcc -S switch_eg_impl.c
 * Created: 2015-08-16
 */

int switch_eg_impl(int x, int n)
{
    /* Table of code pointers */
    static void *jt[7] = {
        &&loc_A, &&loc_def, &&loc_B, 
        &&loc_C, &&loc_D, &&loc_def,
        &&loc_D,
    };

    unsigned index = n - 100;
    int result = x;

    if (index > 6)
        goto loc_def;

    /* Multiway branch */
    goto *jt[index];

loc_def:    /* Default case */
    result = 0;
    goto done;

loc_A:  /* case 100 */
    result *= 3;
    goto done;
    
loc_B:  /* case 102 */
    result += 10;
    /* Fall through */

loc_C:  /* case 103 */
    result += 11;
    goto done;

loc_D: /* case 104, 106 */
    result *= result;
    goto done;

done:
    return result;
}
