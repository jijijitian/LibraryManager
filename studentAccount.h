#pragma once
#include"studentUser.h"
#include<unordered_map>
#include<string>
#include<vector>

struct StudentAccount
{
    public:
        StudentAccount(); //默认构造函数读取本地文件
        void addAccount(StudentUser &studentUser);  //添加账户
        StudentUser findAccount(std::string userName, std::string password);  //查找账户
        bool findAccount(std::string userName);  //查找账户
    private:
        std::unordered_map<std::string, std::vector<std::string>> studentAccount; //学生账户
};