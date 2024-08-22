#include <ncurses.h>
#include <utility>
class Event
{
    public:
        Event();
        std::pair<int,int> getMenuCommands();
};