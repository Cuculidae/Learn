#include <iostream>
class test
{
    friend std::istream &read(std::istream &is, test &item);
    public:
    // fuck! it compiled
    test() { read(std::cin, *this); }
};


std::istream &read(std::istream &is, test &item);
