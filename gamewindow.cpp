#include "gamewindow.h"
GameWindow::GameWindow(int height, int width, int row, int col)
{
    __height = height;
    __width = width;
    __row = row;
    __col = col;
    __gWin = newwin(height, width, row, col);
    box(__gWin, 0, 0);    
}
void GameWindow::state()
{
    char state = 's';
    if(state = 's')
        mvwprintw(__gWin,__height/2,__width/2,"Menu"); //TODO ascii art
        
}
void GameWindow::update()
{
    mvwprintw(__gWin, 1, 1, "Caixa");
    wrefresh(__gWin);
}