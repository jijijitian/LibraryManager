#include"administratorUser.h"
#include<fstream>
#include<iostream>
#include<vector>
#include<string>
#include<sstream>

void AdministratorUser::addBook(Inventory& inventory)
{
    std::string title, author, ISBN, press, type;
    std::cout << "请输入书名：";
    std::cin >> title;
    std::cout << "请输入作者：";
    std::cin >> author;
    std::cout << "请输入ISBN：";
    std::cin >> ISBN;
    std::cout << "请输入出版社：";
    std::cin >> press;
    std::cout << "请输入类型：";
    std::cin >> type;
    Book book(title, author, ISBN, press, type);
    inventory.addBook(book);
    std::ofstream file("inventory.csv", std::ios::app);

    // 检查文件是否成功打开
    if (!file.is_open())
    {
        std::cout << "图书目录出错，请紧急修复！" << std::endl;
        return;
    }

    // 写入图书信息到CSV文件
    file    << title << "," 
            << author << "," 
            << ISBN << ','
            << press << ','
            << type << ','
            << "未借出" << ','
            << "NULL" << ','
            << "NULL" << '\n';
    // 关闭文件
    file.close();
    std::cout << "添加成功！" << std::endl;
}

void AdministratorUser::deleteBook(Inventory& inventory)
{
    std::string ISBN;
    std::cout << "请输入删除书目的ISBN：";
    std::cin >> ISBN;
    Book bookToDelete = inventory.findBook(ISBN,"ISBN");
    if(inventory.getBooks().size() == 0)
    {
        std::cout << "图书目录为空！" << std::endl;
        return;
    }
    else if(!inventory.isExist(bookToDelete))
    {
        std::cout << "图书不存在！" << std::endl;
        return;
    }
    else
    {
        inventory.deleteBook(bookToDelete);
        std::ofstream outFile("inventory.csv");
        for (Book &book : inventory.getBooks())
        {
            outFile << book.getTitle() << ','
                    << book.getAuthor() << ','
                    << book.getISBN() << ','
                    << book.getPress() << ','
                    << book.getType() << ','
                    << book.getStatus()[0] << ','
                    << book.getStatus()[1] << ','
                    << book.getStatus()[2] << '\n';
        }
        std::cout << "删除成功！" << std::endl;
    }
}

/*void AdministratorUser::modifyBook(Inventory &inventory, Book &book)
{
    if(inventory.getBooks().size() == 0)
    {
        std::cout << "图书目录为空！" << std::endl;
        return;
    }
    else if(!inventory.isExist(book))
    {
        std::cout << "图书不存在！" << std::endl;
        return;
    }
    else
    {
        inventory.modifyBook(book);
        std::ofstream outFile("inventory.csv");
        for (Book &book : inventory.getBooks())
        {
            outFile << book.getTitle() << ','
                    << book.getAuthor() << ','
                    << book.getISBN() << ','
                    << book.getPress() << ','
                    << book.getType() << ','
                    << book.getStatus()[0] << ','
                    << book.getStatus()[1] << ','
                    << book.getStatus()[2] << '\n';
        }
        std::cout << "修改成功！" << std::endl;
    }
}*/