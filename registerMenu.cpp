#include<iostream>
#include"registerMenu.h"

void RegisterMenu::printMenu()
{
    std::cout << "1.注册" << std::endl;
    std::cout << "2.返回" << std::endl;
}

void RegisterMenu::printNameInput()
{
    std::cout << "请输入姓名：";
}

void RegisterMenu::printUserNameInput()
{
    std::cout << "请输入用户名：";
}

void RegisterMenu::printPasswordInput()
{
    std::cout << "请输入密码：";
}