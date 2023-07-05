#include "administratorLogin.h"
#include <iostream>

AdministratorUser AdministratorLogin::login(AdministratorAccount &administratorAccount)
{
    system("clear");
    std::string userName, password;
    std::cout << "请输入用户名:";
    std::cin >> userName;
    std::cout << "请输入密码:";
    std::cin >> password;
    AdministratorUser administratorUser = administratorAccount.findAccount(userName, password);
    if (administratorUser.getName() != "NULL")
    {
        return administratorUser;
    }
    else
    {
        return AdministratorUser("NULL", "NULL", "NULL");
    }
}