#include <iostream>
#include <random>

using std::cout;
using std::endl;
using std::default_random_engine;
using std::uniform_real_distribution;

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
 * With one exception, the distribution types are templates that have a single
 * template type parameter that represents the type of the numbers that the
 * distribution generates. These types always generate either a floating-point
 * type or an integral type.
 * Each distribution template has a default template argument. The distribution
 * types that generate floating-point values generate double by default.
 * Distributions that generate integral results use int as their default. When
 * we want to use the default we must remember to follow the template's name
 * with empty angle brackets to signify that we want the default.
 */

int main()
{
    default_random_engine e;    // generates unsigned random integers
    // uniformly distributed from 0 to 1 inclusive
    // empty <> signify we want to use the default result type
    uniform_real_distribution<> u(0, 1);    // generates double by default
    for (size_t i = 0; i < 10; ++i)
        cout << u(e) << ' ';
    cout << endl;

    return 0;
}
