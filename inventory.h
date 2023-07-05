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
    void modifyBook(Book book);  //修改书籍
    bool isExist(Book book);                                // 判断书籍是否存在
    Book findBook(std::string title, std::string findType); // 查找书籍
    std::vector<Book> getBooks();

  private:
    std::vector<Book> books;
};
