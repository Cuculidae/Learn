#include "Screen.hpp"

using std::cout;
using std::endl;

int main(void)
{
    Screen sc(5, 5, '#');
    sc.set('?').display(cout);
    cout << endl;
    sc.move(1,4).set('!').display(cout);
    cout << endl;

    return 0;
}
