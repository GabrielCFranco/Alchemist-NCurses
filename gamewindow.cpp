#include "gamewindow.h"
GameWindow::GameWindow(int height, int width, int row, int col)
{
    __height = height;
    __width = width;
    __row = row;
    __col = col;
    __gWin = newwin(height, width, row, col);
    memset(grid, '.', sizeof(grid));  
    box(__gWin, 0, 0);
    gameState = "menu";  
}
void GameWindow::update(int gameCmd)
{
    if(gameCmd==2);
        //TODO acessar menu
}
void GameWindow::render()
{

    if(gameState=="menu")
    {
        mvwprintw(__gWin,__height/2,__width/2,"Menu"); //TODO ascii art
    }
    wrefresh(__gWin);
}