/**
 * normal_distribution.cpp
 * C++11 normal_distribution function object.
 * Compilation: g++ -o normal_distribution normal_distribution.cpp -std=c++11
 * Created: 2015-10-11
 */

#include <iostream>
#include <random>
#include <vector>
#include <string>
#include <cmath>    // lround

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::default_random_engine;
using std::normal_distribution;

/*
 *******************************************************************************
 *          Distribution Operations
 * Dist d;    Default constructor; makes d ready to use. Other constructors
 *            depend on the type of Dist; The distribution constructors are
 *            explicit.
 * d(e)       Successive calls with the same e produce a sequence of random
 *            numbers according to the distribution type of d; e is a
 *            random-number engine object.
 * d.min()    Return the smallest and largest numbers d(e) will generate.
 * d.max()
 * d.reset()  Reestablish the state of d so that subsequent uses of d don't
 *            depend on values d has already generated.
 *******************************************************************************
 *
 *******************************************************************************
 * template< class RealType = double>           (since C++11)
 * class normal_distribution;
 *******************************************************************************
 * normal_distribution generates random numbers according to the Normal random
 * number distribution. The effect is undefined if RealType is not one of float,
 * double, or long double.
 */

int main()
{
    default_random_engine e;            // generates unsigned random integers
    normal_distribution<> n(4, 1.5);    // mean 4, standard deviation 1.5
    vector<unsigned> vals(9);           // nine elements each 0
    for (size_t i = 0; i != 200; ++i) {
        unsigned v = lround(n(e));      // round to the nearest integer
        if (v < vals.size())            // if this result is in range
            ++vals[v];                  // count how often each number appears
    }
    for (size_t j = 0; j != vals.size(); ++j)
        cout << j << ": " << string(vals[j], '*') << endl;
    cout << "mean: " << n.mean() << " stddev: " << n.stddev() << endl;
    cout << "min: " << n.min() << " max: " << n.max() << endl;

    return 0;
}
