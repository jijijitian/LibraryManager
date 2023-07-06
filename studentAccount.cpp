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
        std::string password;
        std::string name;
        std::string reading1;
        std::string reading2;
        std::string reading3;
        std::vector<std::string> password_name;
        std::vector<std::string> reading;
        getline(ss, userName, ',');
        getline(ss, password, ',');
        getline(ss, name, ',');
        getline(ss, reading1, ',');
        getline(ss, reading2, ',');
        getline(ss, reading3, '\n');
        password_name = {password, name};
        reading = {reading1, reading2, reading3};
        studentAccount.insert(std::make_pair(userName, password_name));
        studentReading.insert(std::make_pair(userName, reading));
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
            return StudentUser(studentAccount[userName][1], userName, password,studentReading[userName]);
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

std::vector<StudentUser> StudentAccount::getUsers()
{
    std::vector<StudentUser> studentUsers;
    for (auto it = studentAccount.begin(); it != studentAccount.end(); ++it)
    {
        studentUsers.push_back(StudentUser(it->second[1], it->first, it->second[0], studentReading[it->first]));
    }
    return studentUsers;
}

void StudentAccount::setStudentReading(std::string userName, std::string title)
{
    for (int index = 0; index < 3; index++)
    {
        if(studentReading[userName][index] == "NULL")
        {
            studentReading[userName][index] = title;
            return;
        }
    }
}

void StudentAccount::deleteStudentReading(std::string userName, std::string title)
{
    for (int index = 0; index < 3; index++)
    {
        if(studentReading[userName][index] == title)
        {
            studentReading[userName].erase(studentReading[userName].begin() + index);
            studentReading[userName].push_back("NULL");
            return;
        }
    }
}