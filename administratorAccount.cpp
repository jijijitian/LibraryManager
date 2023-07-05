#include"administratorAccount.h"
#include <iostream>
#include <fstream>
#include <sstream>

AdministratorAccount::AdministratorAccount()
{
    std::ifstream file("administratorUser.csv");

    // 检查文件是否成功打开
    if (!file.is_open())
    {
        std::cout << "管理员目录出错，请立即修复" << std::endl;
        return;
    }

    // 读取文件中的每一行
    std::string line;
    while (getline(file, line))
    {
        // 将每一行按照逗号分割
        std::stringstream ss(line);
        std::string name, userName, password;
        getline(ss, name, ',');
        getline(ss, userName, ',');
        getline(ss, password, '\n');
        administratorAccount.insert(std::make_pair(userName, password));
    }

    // 关闭文件
    file.close();
}

void AdministratorAccount::addAccount(std::string userName, std::string password)
{
    administratorAccount.insert(std::make_pair(userName, password));
}

bool AdministratorAccount::findAccount(std::string userName, std::string password)
{
    // 检查用户名和密码是否正确
    if (administratorAccount.find(userName) != administratorAccount.end())
    {
        if (administratorAccount[userName] == password)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
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