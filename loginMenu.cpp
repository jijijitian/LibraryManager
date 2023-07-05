#include<iostream>
#include"loginMenu.h"

void LoginMenu::printMenu()
{
  std::cout << "1.学生登录" << std::endl;
  std::cout << "2.学生注册" << std::endl;
  std::cout << "3.管理员登录" << std::endl;
  std::cout << "4.退出" << std::endl;
}