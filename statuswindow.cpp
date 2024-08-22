#include "statuswindow.h"
StatusWindow::StatusWindow(int height, int width, int row, int col)
{
    __height = height; __width = width;
    __row = row; __col = col;
    __sWin = newwin(height, width, row, col);
    box(__sWin, 0, 0);
}
void StatusWindow::render()
{
    wrefresh(__sWin);
}