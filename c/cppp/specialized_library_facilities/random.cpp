/**
 * Compilation: g++ -std=c++11
 * Created: 2015-10-11
 */

#include <iostream>
#include <vector>
#include <ctime>
#include <random>

using std::cout;
using std::endl;
using std::vector;
using std::default_random_engine;
using std::uniform_int_distribution;

/*
 * C++ programs should not use the C library rand function. Instead, they should
 * use the default_random_engine along with an appropriate distribution object.
 *******************************************************************************
 *          Random Number Library Components    (Since C++11)
 * Engine       Types that generate a sequence of random unsigned integers
 * Distribution Types that use an engine to return numbers according to a
 *              particular probability distribution
 *******************************************************************************
 *
 * The random-number engines are function-object classes that define a call
 * operator that takes no arguments and returns a random unsigned number. We can
 * generate raw random numbers by calling an object of a random-number engine
 * type.
 *
 * The library (since C++11) defines several random-number engines that differ
 * in terms of their performance and quality of randomness. Each compiler
 * designates one of these engines as the default_random_engine type. This type
 * is intended to be the engine with the most generally useful properties.
 *
 * For most purposes, the output of an engine is not directly usable, which is
 * why we describe them ealier as raw random numbers. The problem is that the
 * numbers usually span a range that differs from the one we need. Correctly
 * transforming the range of a random number is surprisingly hard. To get a
 * number in a specified range, we use an object of a distribution type.
 *
 * Engines deliver unsigned integers in a system-defined range. The range for
 * rand is 0 to RANDO_MAX. The range for an engine type is returned by calling
 * min and max members on an object of that type.
 *
 *******************************************************************************
 *      Random Number Engine Operations
 * Engine e;    Default constructor; uses the default seed for the engine type
 * Engine e(s); Uses the integral value as the seed
 * e.seed(s);   Reset the state of the engine using the seed s
 * e.min();     The smallest and largest numbers this generator will generate
 * e.max();
 * Engine::result_type  The unsigned integral type this engine generates
 * e.discard(u) Advance the engine by u steps;u has type unsigned long long
 *******************************************************************************
 *
 * A given random-number generator always produces the same sequence of numbers.
 * A function with a local random-number generator should make that generator
 * (both the engine and distribution objects) static. Otherwise, the function
 * will generate the identical sequence on each call.
 *
 * A seed is a valuve that an engine can use to cause it to start generating
 * numbers at a new piont in its sequence. We can seed an engine in one of two
 * ways: we can provide the seed when we create an engine object, or we can call
 * the engine's seed member.
 */

vector<unsigned> good_randVec();

int main()
{
    default_random_engine e;    // generates random unsigned integers
    for (size_t i = 0; i < 10; ++i)
        // e() "calls the object to produce the next random number
        cout << e() << " ";
    cout << endl;

    // uniformly distributed from 0 to 9 inclusive
    uniform_int_distribution<unsigned> u(0, 9);
    for (size_t i = 0; i < 10; ++i) {
        // u uses e as a source of numbers
        // each call returns a uniformly distributed value in the specified range
        cout << u(e) << " ";
    }
    cout << endl;

    cout << "min: " << e.min() << " max: " << e.max() << endl;

    cout << "good_randVec: ";
    for (auto i : good_randVec())   // good_randVec is called once
        cout << i  << ' ';
    cout << endl;
    cout << "good_randVec: ";
    for (auto i : good_randVec())   // good_randVec is called once
        cout << i  << ' ';
    cout << endl;

    default_random_engine e3;       // uses the default seed value
    e3.seed(32767);                 // call seed to set a new seed value
    default_random_engine e4(32767);// set the seed value to 32767
    cout << "e3: ";
    for (size_t i = 0; i < 10; ++i)
        cout << e3() << ' ';
    cout << endl;
    cout << "e4: ";
    for (size_t i = 0; i < 10; ++i)
        cout << e4() << ' ';
    cout << endl;
    // the time function takes a single parameter that is a pointer to a
    // structure into which  to write the time. if that pointer is null, the
    // function just returns the time
    e.seed(time(0));    // a somewhat random seed
    cout << "e: ";
    for (size_t i = 0; i < 10; ++i)
        cout << e() << ' ';
    cout << endl;
    cout << "e: ";
    for (size_t i = 0; i < 10; ++i)
        cout << e() << ' ';
    cout << endl;

    return 0;
}

// returns a vector of 100 uniformly distributed random numbers
vector<unsigned> good_randVec()
{
    // because engines and distributions retain state, they usually should be
    // defined as static so that new numbers are generated on each call
    static default_random_engine e;
    static uniform_int_distribution<unsigned> u(0,9);
    vector<unsigned> ret;
    for (size_t i = 0; i < 10; ++i)
        ret.push_back(u(e));
    return ret;
}
