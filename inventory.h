#pragma once
#include<vector>
#include<string>
#include"book.h"

struct Inventory
{
  public:
    void readInventory(); //读取本地文件
    void addBook(Book book);  //添加书籍
    void deleteBook(Book book);  //删除书籍
    void findBook(std::string title, std::string findType);  //查找书籍
    void storeInventory(); // 储存到本地文件
  private:
    std::vector<Book> books;
};
