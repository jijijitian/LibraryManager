#include"inventory.h"
#include<iostream>
#include<fstream>
#include<sstream>

void Inventory::readInventory()
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
        std::vector<std::string> status;

        getline(ss, title, ',');
        getline(ss, author, ',');
        getline(ss, ISBN, ',');
        getline(ss, press, ',');
        getline(ss, type, ',');
        getline(ss, status[0], ',');  //是否出借
        getline(ss, status[1], ',');  //借阅人
        getline(ss, status[2], ',');  //借阅时间
        Book book(title, author, ISBN, press, type, status);
        books.push_back(book);
    }

    // 关闭文件
    file.close();
}

void Inventory::addBook(Book book)
{
    books.push_back(book);
}

void Inventory::deleteBook(Book book)
{
    for (int i = 0; i < books.size(); i++)
    {
        if (books[i].getTitle() == book.getTitle())
        {
            books.erase(books.begin() + i);
            break;
        }
    }
}

void Inventory::deleteBook(Book book)
{
    for (int i = 0; i < books.size(); i++)
    {
        if (books[i].getTitle() == book.getTitle())
        {
            books.erase(books.begin() + i);
            break;
        }
    }
}

void Inventory::modifyBook(Book book)
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

bool Inventory::isExist(Book book)
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

Book Inventory::findBook(std::string title, std::string findType)
{
    if (findType == "title")
    {
        for (int i = 0; i < books.size(); i++)
        {
            if (books[i].getTitle() == title)
            {
                return books[i];
            }
        }
    }
    else if (findType == "ISBN")
    {
        for (int i = 0; i < books.size(); i++)
        {
            if (books[i].getISBN() == title)
            {
                return books[i];
            }
        }
    }
}

std::vector<Book> Inventory::getBooks()
{
    return books;
}