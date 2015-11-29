#include <iostream>

using std::cout;
using std::endl;

class numbered
{
    public:
        numbered(): mysn(id++) { }
        numbered(const numbered &rhs): mysn(id++) { }
        numbered& operator=(const numbered &rhs) {
            mysn = id++;
            return *this;
        }
        unsigned getId() {
            return mysn;
        }
        static unsigned Id() {
            return id;
        }

    private:
        unsigned mysn;
        static unsigned id;
};

unsigned numbered::id = 0;

numbered f(numbered n) {
    return n;
}

int main()
{
    numbered n0;
    cout << "n0.id: " << n0.getId() << endl;
    cout << "id: " << numbered::Id() << endl;
    numbered n1 = n0;
    cout << "n1.id: " << n1.getId() << endl;
    cout << "id: " << numbered::Id() << endl;
    // return value optimization, even copy constructor has side effect
    numbered n2 = f(n0);    
    cout << "n2.id: " << n2.getId() << endl;
    cout << "id: " << numbered::Id() << endl;
    f(n0);
    cout << "id: " << numbered::Id() << endl;
    return 0;
}
