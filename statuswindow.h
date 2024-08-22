#include <ncurses.h>
class StatusWindow
{
    public:
        StatusWindow(int height, int width, int row, int col);
        void update();
        void render();
    private:
        int __height, __width;
        int __row, __col;
        WINDOW* __sWin;       
};