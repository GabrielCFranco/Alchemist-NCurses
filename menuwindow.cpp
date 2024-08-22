#include "menuwindow.h"
MenuWindow::MenuWindow(int height, int width, int row, int col)
{
    __height = height; __width = width;
    __row = row; __col = col;
    __menuPosX = 0; __menuPosY = 0;
    __mWin = newwin(height, width, row, col);
    box(__mWin, 0, 0);
    __menu.push_back({"Start"});
}
std::pair<int,int>MenuWindow::event()
{
   __input = getch();
   switch(__input)
   {
    case 'W':
        return std::make_pair(0,1);
    case 'A':
        return std::make_pair(-1,0);
    case 'S':
        return std::make_pair(0,-1);
    case 'D':
        return std::make_pair(1,0);
    case '\n': //enter
        return std::make_pair(1,1);
    default:
        return std::make_pair(0,0);    
   } 
}
std::pair<int,int>MenuWindow::getMenuPos()
{
    return 
}
void MenuWindow::update()
{
    //Prints Menu
    for(int i=0;i<__menu.size();i++)
    {
        for(int j=0;j<__menu[j].size();j++)
        {
            mvwprintw(__mWin,
             __height/2+(__menu.size()-1), 
             __width/2+(__menu[j].size()-1), 
             "%s", __menu[i][j].c_str());
        }
    }

    wrefresh(__mWin);
}
