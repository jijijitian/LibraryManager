#include"studentLogin.h"
#include<iostream>

bool StudentLogin::login(StudentAccount& studentAccount)
{
    system("clear");
    std::string userName, password;
    std::cout << "请输入用户名:";
    std::cin >> userName;
    std::cout << "请输入密码:";
    std::cin >> password;
    if (studentAccount.findAccount(userName, password))
    {
        return true;
    }
    else
    {
        return false;
    }
}