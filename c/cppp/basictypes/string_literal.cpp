/**
 * string_literal.cpp
 * Demonstrate string listerals.
 * Compilation: g++ -o string_literal string_literal.c -std=c++11
 * Created: 2015-09-03
 */

#include <iostream>

int main(void)
{
    // in C:   string literal is type char[]
    // in C++: string literal is type const char[]
    const char *s1 = "Narrow string";
    std::cout << s1 << std::endl;

    // const wchar_t[]
    const wchar_t *ws = L"Wide string";
    std::wcout << ws << std::endl;

    // const char[]         (Since C++11)
    const char *s8 = u8"UTF-8 string";
    std::cout << s8 << std::endl;

    // const char16_t[]     (Since C++11)
    const char16_t *s16 = u"UTF-16 string";
    std::cout << s16 << std::endl;

    // const char32_t[]     (Since C++11)
    const char32_t *s32 = U"UTF-32 string";
    std::cout << s32 << std::endl;


    // raw string   (Since C++11)
    const char *rs = R"delim(Raw char string)delim";
    std::cout << rs << std::endl;

    // raw wide string (Since C++11)
    const wchar_t *rws = LR"#(Raw wchar_t string)#";
    std::wcout << rws << std::endl;

    // u8R"", uR"", UR""
}
