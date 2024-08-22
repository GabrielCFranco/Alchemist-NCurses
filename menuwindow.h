#include <ncurses.h>
#include <vector>
#include <string>
#include <cctype>
class MenuWindow
{
    public:
        MenuWindow(int height, int width, int row, int col);
        int event();
        void update(int gameCmd);
        void render();
        std::string getMenuPos();
        std::string getMenu();
        void initScreen();
    private:
        void checkLimits();
        int __height, __width;
        int __row, __col;
        int __menuPos;
        char __input;
        WINDOW* __mWin;
        std::vector<std::string> __menu;
};