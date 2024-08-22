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
        //std::pair<int,int> gameCmd = std::make_pair(0,0);
        std::pair<int,int> gameCmd = menuWin->event();

        gameWin->update();
        menuWin->update(gameCmd);
        menuWin->render();
        gameWin->render();
    }
    endwin();
    return 0;
}
