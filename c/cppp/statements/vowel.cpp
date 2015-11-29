/**
 * vowel.cpp
 * Count how often each of the five vowels appears in some segment of text.
 * Compilation: g++ -o vowel vowel.cpp
 * Created: 2015-11-01
 */

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(void)
{
    /*
     * The control expression of swtich is converted to an integral type.
     * It is an error for any two case labels to have the same value.
     */
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    char ch;
    while (cin >> ch) {
        // if ch is a vowel, increment the appropriate counter
        switch(ch) {
            case 'a':
                ++aCnt;
                break;
            case 'e':
                ++eCnt;
                break;
            case 'i':
                ++iCnt;
                break;
            case 'o':
                ++oCnt;
                break;
            case 'u':
                ++uCnt;
                break;
        }
    }
    // print result
    cout << "Number of vowel a: \t" << aCnt << '\n'
          << "Number of vowel e: \t" << eCnt << '\n'
          << "Number of vowel i: \t" << iCnt << '\n'
          << "Number of vowel o: \t" << oCnt << '\n'
          << "Number of vowel u: \t" << uCnt << endl;

    return 0;
}
