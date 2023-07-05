#include"studentLogin.h"
#include<iostream>

StudentUser StudentLogin::login(StudentAccount& studentAccount)
{
    system("clear");
    std::string userName, password;
    std::cout << "请输入用户名:";
    std::cin >> userName;
    std::cout << "请输入密码:";
    std::cin >> password;
    StudentUser studentUser = studentAccount.findAccount(userName, password);
    if (studentUser.getName() != "NULL")
    {
        return studentUser;
    }
    else
    {
        return StudentUser("NULL", "NULL", "NULL");
    }
}