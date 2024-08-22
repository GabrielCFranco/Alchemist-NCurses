#include "menuwindow.h"
MenuWindow::MenuWindow(int height, int width, int row, int col)
{
    __height = height; __width = width;
    __row = row; __col = col;
    __menuPosX = 0; __menuPosY = 0;
    __mWin = newwin(height, width, row, col);
    box(__mWin, 0, 0);
    __menu.push_back({"Start", "Help"});
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
        return std::make_pair(2,2);
    default:
        return std::make_pair(0,0);    
   } 
}
void MenuWindow::update(std::pair<int,int> gameCmd)
{
    if(gameCmd.first!=2 && gameCmd.second!=2)
        __menuPosX+=gameCmd.first;
        __menuPosY+=gameCmd.second;  
}
void MenuWindow::render()
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
    //Prints >
    checkLimits();
    for(int i=0;i<__menu.size();i++)
    {
        for(int j=0;j<__menu[j].size();j++)
        {
            mvwprintw(__mWin,
             __height/2+(__menu.size()-1), 
             __width/2+(__menu[j].size()-2), 
             ">");
        }
    }
    wrefresh(__mWin);
}
void MenuWindow::checkLimits()
{
    if(__menuPosX<0)
    {
        __menuPosX = 0;
    }
    else if(__menuPosX>=__menu.size())
    {
        __menuPosX = __menu.size()-1;
    }
    if(__menuPosY<0)
    {
        __menuPosY = 0;
    }
    else if(__menuPosY>=__menu.size())
    {
        __menuPosY = __menu.size()-1;
    }
}