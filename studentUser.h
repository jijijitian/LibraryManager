#pragma once
#include"user.h"
#include"studentAccount.h"
#include"inventory.h"
#include<vector>
#include<string>

struct StudentAccount;

struct StudentUser:public User
{
    public:
        StudentUser();
        StudentUser(std::string name, std::string userName, std::string password);
        StudentUser(std::string name, std::string userName, std::string password, std::vector<std::string> reading);
        std::vector<std::string> getReading();  //获取正在阅读的书籍
        void reading();     // 正在阅读
        void borrowBook(StudentAccount &account, Inventory &inventory); // 借书
        void returnBook(StudentAccount &account, Inventory &inventory);   // 还书
        void storeStudentUser(StudentAccount& account);  //储存到本地文件
    private:
        std::vector<std::string> m_reading;
};