/**
 * application.cpp
 * C++11 explict instantiation.
 * Compilation: g++ -o application application.cpp templateBuild.o -std=c++11
 * Created: 2015-09-27
 */

#include "templateBuild.hpp"

using std::string;

int main(void)
{
    Blob<string> sa1, sa2;  // instantiation will appear elsewhere
    // Blob<int> and its initializer_list constructor instantiated in this file
    Blob<int> a1 = {0,1,2,3,4,5,6,7,8,9};
    Blob<int> a2(a1);   // copy constructor instantiated in this file
    int i = compare(a1[0], a2[0]);  // instantiation will appear elsewhere

    return 0;
}
