#ifndef WINDOW_MGR_HPP
#
#define WINDOW_MGR_HPP
#
#include <iostream>
#include <string>
#include <vector>

class Screen;

class Window_mgr
{
    public:
        using ScreenIndex = std::vector<Screen>::size_type;
        // reset the Screen at the given position to all blanks
        void clear(ScreenIndex i);
        // add a Screen to window and return its index
        ScreenIndex addScreen(const Screen&);

    private:
        std::vector<Screen> screens;
};

#include "Screen.hpp"

inline
Window_mgr::Window_mgr(): screens{Screen(24, 80, ' ')} { }

void Window_mgr::clear(ScreenIndex i)
{
    Screen &s = screens[i];
    s.contents = std::string(s.width*s.height, ' ');
}

Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &s)
{
    screens.push_back(s);
    return screens.size() - 1;
}

#endif
