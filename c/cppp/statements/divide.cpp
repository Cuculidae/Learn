/**
 * divide.cpp
 * Reads two numbers and divides them.
 * Compilation: g++ -o divide divide.cpp
 * Created: 2015-11-02
 */

#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;

int main()
{
    int i = 0, j = 0;
    while (cin >> i >> j) {
        try {
            if (j == 0) throw runtime_error("division by ZERO");
            cout << i << "/" << j << " = " << static_cast<double>(i)/j << endl;
        } catch (runtime_error err) {
            cout << err.what()
                 << "\nTry Again? Enter y or n" << endl;
            char c;
            cin >> c;
            if (!cin || c == 'n')
                break;
        }
    }

    return 0;
}
