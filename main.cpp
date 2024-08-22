#include <ncurses.h>
#include <string>
#include <vector>
#include "menuwindow.h"
#include "gamewindow.h"



int main()
{
    initscr();             
    cbreak();              
    noecho();              
    curs_set(0);
    GameWindow *gameWin = new GameWindow((LINES/4)*3, COLS, 0, 0);
    MenuWindow *menuWin = new MenuWindow(LINES/4, COLS, LINES/4*3, 0);
    while(1)
    {   
        menuWin->event();
        gameWin->state();
        gameWin->update();
        menuWin->update();
    }
    endwin();
    return 0;
}
