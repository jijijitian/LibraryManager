#include"user.h"

class StudentUser:public User
{
    public:
        void reading();  //正在阅读
        void borrowBook();  //借书
        void returnBook();  //还书
        void storeStudentUser();  //储存到本地文件
};