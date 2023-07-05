#include "administratorMainWindow.h"
#include "administratorUser.h"
#include <iostream>

void AdministratorMainWindow::printMenu()
{
    std::cout << "欢迎登陆管理系统！" << std::endl;
    std::cout << "1.书籍列表" << std::endl;
    std::cout << "2.增加书籍" << std::endl;
    std::cout << "3.删除书籍" << std::endl;
    std::cout << "4.更改书籍" << std::endl;
    std::cout << "5.退出登录" << std::endl;
    std::cout << "6.退出程序" << std::endl;
}