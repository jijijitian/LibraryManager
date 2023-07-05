#include "studentAccount.h"
#include <iostream>
#include <fstream>
#include <sstream>

StudentAccount::StudentAccount()
{
    std::ifstream file("studentUser.csv");

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
        std::vector<std::string> password_name;
        getline(ss, userName, ',');
        getline(ss, password_name[0], ',');
        getline(ss, password_name[1], '\n');
        studentAccount.insert(std::make_pair(userName, password_name));
    }

    // 关闭文件
    file.close();
}

void StudentAccount::addAccount(StudentUser &studentUser)
{
    std::vector<std::string> password_name = {studentUser.getPassword(), studentUser.getName()};
    studentAccount.insert(std::make_pair(studentUser.getUserName(), password_name));
}

StudentUser StudentAccount::findAccount(std::string userName, std::string password)
{
    // 检查用户名和密码是否正确
    if (studentAccount.find(userName) != studentAccount.end())
    {
        if (studentAccount[userName][0] == password)
        {
            return StudentUser(studentAccount[userName][1], userName, password);
        }
        else
        {
            return StudentUser("NULL", "NULL", "NULL");
        }
    }
    else
    {
        return StudentUser("NULL", "NULL", "NULL");
    }
}

bool StudentAccount::findAccount(std::string userName)
{
    // 检查用户名是否存在
    if (studentAccount.find(userName) != studentAccount.end())
    {
        return true;
    }
    else
    {
        return false;
    }
}