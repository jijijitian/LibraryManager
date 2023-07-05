#pragma once
#include <unordered_map>
#include <string>
#include<vector>
#include"administratorUser.h"

struct AdministratorAccount
{
    public:
        AdministratorAccount();  // 默认构造函数读取本地文件
        void addAccount(AdministratorUser &administratorUser);  // 添加账户
        AdministratorUser findAccount(std::string userName, std::string password); // 查找账户
        bool findAccount(std::string userName);                       // 查找账户
    private:
        std::unordered_map<std::string, std::vector<std::string>> administratorAccount;
};