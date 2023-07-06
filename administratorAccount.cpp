#include "administratorAccount.h"
#include <iostream>
#include <fstream>
#include <sstream>

AdministratorAccount::AdministratorAccount()
{
    std::ifstream file("administratorUser.csv");

    // 检查文件是否成功打开
    if (!file.is_open())
    {
        std::cout << "用户目录出错，请联系管理员" << std::endl;
        return;
    }

    // 读取文件中的每一行
    std::string line;
    while (getline(file, line))
    {
        // 将每一行按照逗号分割
        std::stringstream ss(line);
        std::string userName;
        std::string password;
        std::string name;
        std::vector<std::string> password_name = {"NULL", "NULL"};
        getline(ss, userName, ',');
        getline(ss, password, ',');
        getline(ss, name, '\n');
        password_name = {password, name};
        administratorAccount.insert(std::make_pair(userName, password_name));
    }

    // 关闭文件
    file.close();
}

void AdministratorAccount::addAccount(AdministratorUser &administratorUser)
{
    std::vector<std::string> password_name = {administratorUser.getPassword(), administratorUser.getName()};
    administratorAccount.insert(std::make_pair(administratorUser.getUserName(), password_name));
}

AdministratorUser AdministratorAccount::findAccount(std::string userName, std::string password)
{
    // 检查用户名和密码是否正确
    if (administratorAccount.find(userName) != administratorAccount.end())
    {
        if (administratorAccount[userName][0] == password)
        {
            return AdministratorUser(administratorAccount[userName][1], userName, password);
        }
        else
        {
            return AdministratorUser("NULL", "NULL", "NULL");
        }
    }
    else
    {
        return AdministratorUser("NULL", "NULL", "NULL");
    }
}

bool AdministratorAccount::findAccount(std::string userName)
{
    // 检查用户名是否存在
    if (administratorAccount.find(userName) != administratorAccount.end())
    {
        return true;
    }
    else
    {
        return false;
    }
}