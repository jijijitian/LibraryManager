#include"studentMainWindow.h"
#include"studentUser.h"
#include<iostream>

void StudentMainWindow::printMenu()
{
    std::cout << "欢迎登陆学生借阅系统！" << std::endl;
    std::cout << "1.借书" << std::endl;
    std::cout << "2.当前借阅" << std::endl;
    std::cout << "3.还书" << std::endl;
    std::cout << "4.退出登录" << std::endl;
    std::cout << "5.退出程序" << std::endl;
}