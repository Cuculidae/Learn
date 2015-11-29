/**
 * count.cpp
 * Demonstrate if statement, count how many
 * consecutive times each distinct value 
 * appears in the input.
 * Compilation: g++ -o count count.cpp
 * Created: 2015-09-03
 */

#include <iostream>

int main(void)
{
    // currVal is the number we're counting; we will read new values into val
    int currVal = 0, val = 0;
    
    // read first number and ensure that we have data to process
    if (std::cin >> currVal) {
        int cnt = 1;    // store the count for the current value we're processing
        while (std::cin >> val) {   // read the remaining numbers
            if (val == currVal)     // if the values are the same
                ++cnt;
            else {  // otherwise, print the count for the previous value
                std::cout << currVal << " occurs "
                    << cnt << "times" << std::endl;
                currVal = val;  // remember the new value
                cnt = 1;        // reset the counter
            }
        }   // end-while
        // remember to print the count for the last value in the file
        std::cout << currVal << " occurs "
            << cnt << " times" << std::endl;
    }   // end-if

    return 0;
}
