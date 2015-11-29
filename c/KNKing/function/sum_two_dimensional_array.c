/**
 * Chapter 9 Functions
 * sum_two_dimensional_array.c
 */

#include <stdio.h>

int sum_tow_dimensional_array(int n, int m, int a[n][m]); // Since C99, VLA
int sum_tow_dimensional_array(int n, int m, int a[*][*]); // the same
int sum_tow_dimensional_array(int n, int m, int a[][m]);  // the same
int sum_tow_dimensional_array(int n, int m, int a[][*]);  // the same

int main(void)
{
    int total = sum_tow_dimensional_array(3, 3, (int [3][3]) {1,2,3,4,5,6,7,8,9});
    printf("total = %d\n", total);
}

int sum_tow_dimensional_array(int n, int m, int a[n][m])
{
    int sum = 0;

    for (int i=0; i < n; ++i)
        for (int j=0; j < m; ++j)
            sum += a[i][j];

    return sum;
}
