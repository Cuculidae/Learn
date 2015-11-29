/**
 * char_literal.cpp
 * Demonstrate char literal
 * Compilation: g++ -o char_literal char_literal.cpp -std=C++11
 * Created: 2015-09-03
 */

#include <iostream>

int main(void)
{
    // type char (unlike in C, which has type int)
    char c = 'a';
    
    // type wchat_t
    wchar_t wc = L'a';

    // type int, implementation-defined value
    int ic = 'ab';

    // type char, ISO 10646 code point (Since C++17)
    //char uc = u8'a';

    // type char16_t,   (Since C++11)
    char16_t c16 = u'a';

    // type char32_t    (Since C++11)
    char32_t c32 = U'a';

}
