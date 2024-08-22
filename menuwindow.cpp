#include "menuwindow.h"
MenuWindow::MenuWindow(int height, int width, int row, int col)
{
    __height = height; __width = width;
    __row = row; __col = col;
    __menuPos = 0;
    __mWin = newwin(height, width, row, col);
    box(__mWin, 0, 0);
    initScreen();
}
int MenuWindow::event()
{
   __input = wgetch(__mWin);
   __input = std::toupper(__input);
   switch(__input)
   {
    case 'W':
        return -1;
    case 'S':
        return 1;
    case '\n': //its working
        return 2;
    default:
        return 0;
   } 
}
void MenuWindow::update(int gameCmd)
{
    if(gameCmd!=2)
        __menuPos+=gameCmd;
}
void MenuWindow::render()
{
    //Prints Menu
    checkLimits();
    for(int i=0;i<__menu.size();i++)
    {
        mvwprintw(__mWin, 1+i, 2, "%s", __menu[i].c_str());
        if(i==__menuPos)
            mvwprintw(__mWin, 1+i, 1, ">");
        else   
            mvwprintw(__mWin, 1+i, 1, " ");
    }
    wrefresh(__mWin);
}
void MenuWindow::checkLimits()
{
    if(__menuPos<0)
    {
        __menuPos = __menu.size()-1;
    }
    else if(__menuPos>=__menu.size())
    {
        __menuPos = 0;
    }
}  
void MenuWindow::initScreen()
{
    if(!__menu.empty())
        __menu.clear();
    __menu.push_back("Start");
    __menu.push_back("Help");
    __menu.push_back("Exit");
} 