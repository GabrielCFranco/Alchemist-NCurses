#include <ncurses.h>
class GameWindow
{
    public:
        GameWindow(int height, int width, int row, int col);
        void state();
        void update();
    private:
        int __height;
        int __width;
        int __row;
        int __col;
        WINDOW* __gWin;
};