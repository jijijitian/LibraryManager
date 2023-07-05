#include"administratorUser.h"
#include<fstream>
#include<iostream>
#include<vector>
#include<string>
#include<sstream>

void AdministratorUser::addBook(Inventory& inventory, Book& book)
{
    inventory.addBook(book);
    std::ofstream file("inventory.csv", std::ios::app);

    // 检查文件是否成功打开
    if (!file.is_open())
    {
        std::cout << "图书目录出错，请紧急修复！" << std::endl;
        return;
    }

    // 写入图书信息到CSV文件
    file << book.getTitle() << "," << book.getAuthor() << "," << book.getISBN() << book.getPress() << book.getType() << '\n';
    inventory.addBook(book);
    // 关闭文件
    file.close();
}

void AdministratorUser::deleteBook(Inventory& inventory, Book& bookToDelete)
{
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

void AdministratorUser::modifyBook(Inventory &inventory, Book &book)
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
}