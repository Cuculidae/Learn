/**
 * delegating.cpp
 * C++ delegating contructors.
 * Compilation: g++ -o delegating delegating.cpp -std=c++11
 * Created: 2015-09-12
 */

#include <iostream>

/*
 * A delegating constructor uses another constructor from its own class to
 * perform its initialization. In a delegating constructor, the member
 * initializer list has a single entry that is the name of the class itself.
 * Like other member initializers, the name of the class is followed by a
 * parenthesized list of arguments. The argument list must match another
 * constructor in the class.
 */

class X
{
    public:
        X(int v1, int v2) : i(v1), j(v2) {
            std::cout << "in X(int, int)" << std::endl;
        }
        X(): X(1, 1) {
            std::cout << "in X()" << std::endl;
        }
        
    private:
        int i;
        int j;
};

int main(void)
{
    X x;

    return 0;
}
