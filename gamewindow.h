#include <ncurses.h>
#include <string>
#include <cstring>
class GameWindow
{
    public:
        GameWindow(int height, int width, int row, int col);
        void update(int gameCmd);
        void render();
    private:
        int __height, __width;
        int __row, __col;
        char grid[10][10]; 
        WINDOW* __gWin;
        std::string gameState;
};      