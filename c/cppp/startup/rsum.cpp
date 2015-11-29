/**
 * Reads an unknown number of inputs, calculates
 * and outputs the running sum.
 * Compilation: g++ -o rsum rsum.c
 * Created: 2015-09-03
 */

#include <iostream>

int main(void)
{
    int sum = 0, value;

    // read until the input stream is invalid
    // calculating a running total of values read
    // An istream becomes invalid when we hit the 
    // end-of-file or encouter an invalid input
    while (std::cin >> value)
        sum += value;
    std::cout << "Sum is: " << sum << std::endl;

    return 0;
}
