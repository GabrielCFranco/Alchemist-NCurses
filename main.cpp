#include <ncurses.h>
#include "menuwindow.h"
#include "gamewindow.h"
#include "statuswindow.h"
int main()
{
    initscr();             
    cbreak();              
    noecho();              
    curs_set(0);
    GameWindow *gameWin = new GameWindow((LINES/4)*3, COLS, 0, 0);
    MenuWindow *menuWin = new MenuWindow(LINES/4, COLS/2, LINES/4*3, 0);
    StatusWindow *statusWin = new StatusWindow(LINES/4,COLS/2,LINES/4*3,COLS/2);  
    int gameCmd=0;
    while(1)
    {   
        menuWin->update(gameCmd);
        gameWin->update(gameCmd);
        gameWin->render();
        menuWin->render();
        statusWin->render();
        gameCmd = menuWin->event();
    }
    endwin();
    return 0;
}
