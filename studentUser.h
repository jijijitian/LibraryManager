#pragma once
#include"user.h"
#include"studentAccount.h"

class StudentUser:public User
{
    public:
        StudentUser(std::string name, std::string userName, std::string password):User(name, userName, password){}
        void reading();     // 正在阅读
        void borrowBook();  //借书
        void returnBook();  //还书
        void storeStudentUser(StudentAccount& account);  //储存到本地文件
};