/**
 * if.cpp
 * Demonstrate the usage of if statement.
 * Reads an integer grade, and outputs its corresponding letter grade.
 * Compilation: g++ -o if if.cpp -std=c++11
 * Created: 2015-09-08
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
    // F:<60, D:60~69, ... A:90~99, A++:100 
    const vector<string> scores = {"F", "D", "C", "B", "A", "A++"};

    // read the integer grade
    int grade = 0;
    cout << "Enter you grade: ";
    cin >> grade;

    // if grade is less than 60 it's an F, otherwise compute a subscript
    string lettergrade;
    if (grade < 60) {   // if failing grade, no need to check for a + or -
        lettergrade = scores[0];
    }
    else {
        lettergrade = scores[(grade - 50) / 10];    // fetch the letter grade
        if (grade != 100) {         // add a + or - only if not already an A++
            if (grade % 10 > 7) {
                lettergrade += '+';     // grades ending in 8 or 9 get a +
            }
            else if (grade % 10 < 3) {
                lettergrade += '-';     // grades ending in 0, 1 or 2 get a -
            }
        }
    }

    cout << "Your letter grade is " << lettergrade << endl;

    return 0;
}
