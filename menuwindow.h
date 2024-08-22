#include <ncurses.h>
#include <vector>
#include <string>
#include <utility>
class MenuWindow
{
    public:
        MenuWindow(int height, int width, int row, int col);
        std::pair<int,int> event();
        std::pair<int,int>getMenuPos();
        void state();
        void update();
    private:
        int __height, __width;
        int __row, __col;
        int __menuPosX, __menuPosY;
        char __input;
        WINDOW* __mWin;
        std::vector<std::vector<std::string>> __menu;
};