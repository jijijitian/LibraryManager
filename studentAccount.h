#pragma once
#include<unordered_map>
#include<string>

struct StudentAccount
{
    public:
        StudentAccount(); //默认构造函数读取本地文件
        void addAccount(std::string userName, std::string password);  //添加账户
        bool findAccount(std::string userName, std::string password);  //查找账户
        bool findAccount(std::string userName);  //查找账户

    private:
        std::unordered_map<std::string, std::string> studentAccount;
};