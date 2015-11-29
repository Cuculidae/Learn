/**
 * bernoulli_distribution.cpp
 * C++11 <random> bernoulli_distribution.
 * Compilation: g++ -o bernoulli_distribution bernoulli_distribution.cpp -std=c++11
 * Created: 2015-10-11
 */

#include <iostream>
#include <random>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::default_random_engine;
using std::bernoulli_distribution;

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
 * class bernoulli_distribution;    (since C++11)
 * Produces random boolean values, according to the bernoulli distribution.
 *******************************************************************************
 *
 * The bernoulli_distribution is an ordinary class, not a template. This
 * distribution always returns a bool value. It returns true with a given
 * probability. By default that probability is 0.5.
 */

int main()
{
    default_random_engine e;        // e has state, so it must be outside the loop!
    bernoulli_distribution b;       // 0.5/0.5
    // print the bernoulli distribution parameter
    cout << "p: " << b.p() << endl;
    size_t hist[2] = {};
    for (int i = 0; i < 10000; ++i) {
        ++hist[b(e)];
    }
    cout << "false: " << string(hist[0]/500, '*') << endl;
    cout << "true:  " << string(hist[1]/500, '*') << endl;

    return 0;
}
