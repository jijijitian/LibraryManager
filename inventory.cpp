#include"inventory.h"
#include<iostream>
#include<fstream>
#include<sstream>

Inventory::Inventory()
{
    std::ifstream file("inventory.csv");

    // 检查文件是否成功打开
    if (!file.is_open())
    {
        std::cout << "书籍目录出错，请及时修复！" << std::endl;
        return;
    }

    // 读取文件
    std::string line;
    while (getline(file, line))
    {
        std::stringstream ss(line);
        std::string title;
        std::string author;
        std::string ISBN;
        std::string press;
        std::string type;
        std::string borrowimgStatus;
        std::string borrower;
        std::string borrowDate;
        std::vector<std::string> status;

        getline(ss, title, ',');
        getline(ss, author, ',');
        getline(ss, ISBN, ',');
        getline(ss, press, ',');
        getline(ss, type, ',');
        getline(ss, borrowimgStatus, ',');  //是否出借
        getline(ss, borrower, ',');  //借阅人
        getline(ss, borrowDate, '\n');  //借阅时间
        status = {borrowimgStatus, borrower, borrowDate};
        Book book(title, author, ISBN, press, type, status);
        books.push_back(book);
    }

    // 关闭文件
    file.close();
}

void Inventory::addBook(Book &book)
{
    books.push_back(book);
}

void Inventory::deleteBook(Book &book)
{
    for (int index = 0; index < books.size(); index++)
    {
        if (books[index].getISBN() == book.getISBN())
        {
            books.erase(books.begin() + index);
            break;
        }
    }
}

void Inventory::modifyBook(Book &book)
{
    for (int i = 0; i < books.size(); i++)
    {
        if (books[i].getISBN() == book.getISBN())
        {
            books[i] = book;
            break;
        }
    }
}

void Inventory::printBookList()
{
    bool flag = 1;
    for (int i = 0; i < books.size(); i++)
    {
        std::cout << "书名：" << books[i].getTitle() << '\t';
        std::cout << "作者：" << books[i].getAuthor() << '\t';
        std::cout << "ISBN：" << books[i].getISBN() << '\t';
        std::cout << "出版社：" << books[i].getPress() << '\t';
        std::cout << "类型：" << books[i].getType() << '\t';
        std::cout << "借阅状态：" << books[i].getStatus()[0] << '\t';
        if(books[i].getStatus()[0] == "已借出")
        {
            std::cout << "借阅人：" << books[i].getStatus()[1] << '\t';
            std::cout << "借阅时间：" << books[i].getStatus()[2] << '\t';
        }
        flag = 0;
        std::cout << std::endl;
    }
    if(flag)
    {
        std::cout << "当前没有书籍" << std::endl;
    }
}

bool Inventory::isExist(Book &book)
{
    for (int i = 0; i < books.size(); i++)
    {
        if (books[i].getTitle() == book.getTitle())
        {
            return true;
        }
    }
    return false;
}

Book Inventory::findBook(std::string strToFind, std::string findType)
{
    if (findType == "title")
    {
        for (int i = 0; i < books.size(); i++)
        {
            if (books[i].getTitle() == strToFind)
            {
                return books[i];
            }
        }
    }
    else if (findType == "ISBN")
    {
        for (int i = 0; i < books.size(); i++)
        {
            if (books[i].getISBN() == strToFind)
            {
                return books[i];
            }
        }
    }
    return Book("NULL", "NULL", "NULL", "NULL", "NULL", {"NULL", "NULL", "NULL"});
}

std::vector<Book> Inventory::getBooks()
{
    return books;
}