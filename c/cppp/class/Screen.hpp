#ifndef SCREEN_HPP
#
#define SCREEN_HPP
#
#include <iostream>
#include <string>

/*
 * Unlike ordinary members, members that define types must appear before they
 * are used.
 *
 * Althogh we are not required to do so, it is legal to specify inline on both
 * declaration and definition. For the same reasons that we define inline
 * functions in headers, inline members should be defined in the same header as
 * the corresponding class definition.
 *
 * A mutable data member is never const, even when it is a member of a const
 * object. Accordingly, a const member function may change a mutable member.
 *
 * We can refer to a class type directly by using the class name as a type name.
 * Alternatively, we can use the class name following the keyword class or
 * struct.
 *
 * We can use an incomplete type in only limited ways: we can define pointers or
 * references to such types, and we can declare (but not define) functions that
 * use an incomplete type as a parameter or return type.
 *
 * A class can also make another class its friend or it can declare specific
 * member functions of another (previously defined) class as friends.
 * In addition, a friend function can be defined inside the class body. Such
 * functions are implicitly inline. Friendship is not transitive.
 *
 * Classes and nonmember functions need not have been declared before they are
 * used in a friend declaration. Even if we define the function inside the
 * class, we must still provide a declaration outside of th class itself to make
 * that function visible. A declaration must exist even if we only call the
 * friend from members of the friendshiop granting class.
 */

class Window_mgr;

class Screen
{
    //friend class Window_mgr;
    friend void Window_mgr::clear(ScreenIndex i);

    public:
        typedef std::string::size_type pos;
        Screen();
        Screen(pos ht, pos wd, char c);
        char get() const;
        char get(pos r, pos c) const;
        Screen &set(char c);
        Screen &set(pos r, pos c, char ch);
        Screen &move(pos r, pos c);
        Screen &display(std::ostream &os);
        const Screen &display(std::ostream &os) const;

    private:
        void do_display(std::ostream &os) const;
        pos cursor = 0;
        pos height = 0, width = 0;
        std::string contents;
};

inline
Screen::Screen() = default;

inline
Screen::Screen(pos ht, pos wd,  char c):
    height(ht), width(wd), contents(ht*wd, c) { }

inline
char Screen::get() const
{
    return contents[cursor];
}

inline
char Screen::get(pos r, pos c) const
{
    pos row = r * width;        // compute row location
    return contents[row + c];   // return character at the given column
}

inline
Screen &Screen::set(char c)
{
    contents[cursor] = c;       // set the new value at the current cursor
    return *this;               // return this object as an lvalue
}

inline
Screen &Screen::set(pos r, pos c, char ch)
{
    contents[r*width  + c] = ch;  // set specified location to given value
    return *this;               // return this object as an lvalue
}

inline
Screen &Screen::move(pos r, pos c)
{
    pos row = r * width;        // compute the row location
    cursor = row + c;           // move cursor to the column within that row
    return *this;               // return this objects as an lvalue
}

inline
Screen &Screen::display(std::ostream &os)
{
    do_display(os);
    return *this;
}

inline
const Screen &Screen::display(std::ostream &os) const
{
    do_display(os);
    return *this;
}

inline
void Screen::do_display(std::ostream &os) const
{
    os << contents;
}
#endif
