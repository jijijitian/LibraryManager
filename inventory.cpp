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
        std::cout << "书籍目录出错，请联系管理员" << std::endl;
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
        getline(ss, status[0], ',');
        getline(ss, status[1], ',');
        getline(ss, status[2], ',');
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

void Inventory::findBook(std::string title, std::string findType)
{
    if (findType == "title")
    {
        for (int i = 0; i < books.size(); i++)
        {
            if (books[i].getTitle() == title)
            {
                std::cout << "书名：" << books[i].getTitle() << std::endl;
                std::cout << "作者：" << books[i].getAuthor() << std::endl;
                std::cout << "ISBN：" << books[i].getISBN() << std::endl;
                std::cout << "出版社：" << books[i].getPress() << std::endl;
                std::cout << "类型：" << books[i].getType() << std::endl;
                break;
            }
        }
    }
    else if (findType == "ISBN")
    {
        for (int i = 0; i < books.size(); i++)
        {
            if (books[i].getISBN() == title)
            {
                std::cout << "书名：" << books[i].getTitle() << std::endl;
                std::cout << "作者：" << books[i].getAuthor() << std::endl;
                std::cout << "ISBN：" << books[i].getISBN() << std::endl;
                std::cout << "出版社：" << books[i].getPress() << std::endl;
                std::cout << "类型：" << books[i].getType() << std::endl;
                break;
            }
        }
    }
}