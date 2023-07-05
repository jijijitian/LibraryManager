#include"user.h"
#include "inventory.h"
#include"book.h"

struct AdministratorUser:public User
{
    public:
        void addBook(Inventory& inventory, Book& book);  //添加书籍
        void deleteBook(Inventory &inventory, Book &book); // 删除书籍
        void modifyBook(Inventory &inventory, Book &book); // 修改书籍
};