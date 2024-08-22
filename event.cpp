#include "event.h"
Event::Event(){}
std::pair<int,int>Event::getMenuCommands()
{
    char input = getch();
    switch(input)
    {
        case 'W':
            return std::make_pair(0,1);
        case 'A':
            return std::make_pair(1,0);
        case 'S':
            return std::make_pair(0,-1);
        case 'D':
            return std::make_pair(-1,0);
        case '\n':
            return std::make_pair(1,1);
        default:
            return std::make_pair(0,0);
    }
}