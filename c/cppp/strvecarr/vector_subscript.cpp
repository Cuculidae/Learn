/**
 * vector_substript.cpp
 * Create: 2015-09-07
 */

#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

int main(void)
{
    /*
     * The subscript operator on vector (and string) fetches an existing
     * element; it does not add an element.
     * The type of the subsript is the corresponding size_type.
     * To use size_type, we must name the type in which it is defined.
     * A vector type always includes its element type.
     */

    // count the number of grades by clusters of ten:0-9,10-19...90-99,100
    vector<unsigned> scores(11, 0); // 11 buckets, all initially 0
    unsigned grade;
    while (cin >> grade) {      // read the grades
        if (grade <= 100)       // handle only valid grades
            ++scores[grade/10]; // increment the counter for the current cluster
    }

    for (auto score : scores)
        cout << score << " ";
    cout << endl;

    return 0;
}
