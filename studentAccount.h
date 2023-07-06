#pragma once
#include"studentUser.h"
#include<unordered_map>
#include<string>
#include<vector>

struct StudentUser;

struct StudentAccount
{
    public:
        StudentAccount(); //默认构造函数读取本地文件
        void addAccount(StudentUser &studentUser);  //添加账户
        StudentUser findAccount(std::string userName, std::string password);  //查找账户
        bool findAccount(std::string userName);  //查找账户
        std::vector<StudentUser> getUsers();
        void setStudentReading(std::string userName, std::string title);  //设置学生正在阅读的书籍
        void deleteStudentReading(std::string userName, std::string title);  //删除学生正在阅读的书籍
    private:
        std::unordered_map<std::string, std::vector<std::string>> studentAccount; //学生账户(用户名-密码、姓名)
        std::unordered_map<std::string, std::vector<std::string>> studentReading; //学生正在阅读的书籍
};