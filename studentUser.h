#pragma once
#include"user.h"
#include"studentAccount.h"

class StudentUser:public User
{
    public:
        void reading();  //正在阅读
        void borrowBook();  //借书
        void returnBook();  //还书
        void storeStudentUser(StudentAccount& account);  //储存到本地文件
        static int serialNumber; // 学生用户序号
};