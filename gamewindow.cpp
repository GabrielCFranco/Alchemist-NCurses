#include "gamewindow.h"
GameWindow::GameWindow(int height, int width, int row, int col)
{
    __height = height;
    __width = width;
    __row = row;
    __col = col;
    __gWin = newwin(height, width, row, col);
    box(__gWin, 0, 0);  
    memset(grid, '.', sizeof(grid));  
}
void GameWindow::update()
{
    
}
void GameWindow::render()
{
    mvwprintw(__gWin,__height/2,__width/2,"menu"); //TODO ascii art
    wrefresh(__gWin);
}