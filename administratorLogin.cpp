#include "administratorLogin.h"
#include <iostream>

bool AdministratorLogin::login(AdministratorAccount &administratorAccount)
{
    system("clear");
    std::string userName, password;
    std::cout << "请输入用户名:";
    std::cin >> userName;
    std::cout << "请输入密码:";
    std::cin >> password;
    if (administratorAccount.findAccount(userName, password))
    {
        return true;
    }
    else
    {
        return false;
    }
}