#include"login.h"
#include<iostream>

bool Login::checkAccount(StudentAccount& account)
{
    std::string userName;
    std::string password;

    std::cout << "请输入用户名：";
    std::cin >> userName;
    std::cout << "请输入密码：";
    std::cin >> password;

    // 检查用户名和密码是否正确
    if (account.findAccount(userName, password))
    {
        std::cout << "登录成功" << std::endl;
        return true;
    }
    else
    {
        std::cout << "用户名或密码错误" << std::endl;
        return false;
    }
}