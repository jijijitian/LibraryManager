#include"login.h"
#include<iostream>

bool Login::checkAccount(StudentUser& user, StudentAccount& account)
{

    // 检查用户名和密码是否正确
    if (account.findAccount(user.getName(), user.getPassword()))
    {
        return true;
    }
    else
    {
        return false;
    }
}