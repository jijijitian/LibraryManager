#pragma once
#include"user.h"
#include "inventory.h"
#include"book.h"

struct AdministratorUser:public User
{
    public:
        AdministratorUser(std::string name, std::string userName, std::string password):User(name, userName, password){}
        void addBook(Inventory& inventory);  //添加书籍
        void deleteBook(Inventory &inventory); // 删除书籍
        //void modifyBook(Inventory &inventory, Book &book); // 修改书籍
};