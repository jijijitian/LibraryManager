#include"studentUser.h"
#include<chrono>
#include<fstream>
#include<sstream>
#include<iostream>

StudentUser::StudentUser():User()
{
    m_reading = {"NULL", "NULL", "NULL"};
}

StudentUser::StudentUser(std::string name, std::string userName, std::string password):User(name, userName, password)
{
    m_reading = {"NULL", "NULL", "NULL"};
}

StudentUser::StudentUser(std::string name, std::string userName, std::string password, std::vector<std::string> reading) : User(name, userName, password)
{
    m_reading = reading;
}

void StudentUser::reading()
{
    bool flag = 1;
    for (int index = 0; index < m_reading.size(); index++)
    {
        if(m_reading[index] != "NULL")
        {
            std::cout << m_reading[index] << std::endl;
            flag = 0;
        }
    }
    if(flag)
    {
        std::cout << "当前未借阅任何书籍！" << std::endl;
    }
}

std::vector<std::string> StudentUser::getReading()
{
    return m_reading;
}

void StudentUser::borrowBook(StudentAccount &studentAccount, Inventory &inventory)
{
    if(m_reading[0] != "NULL" && m_reading[1] != "NULL" && m_reading[2] != "NULL")
    {
        std::cout << "当前已借阅三本书籍，无法借阅更多书籍！" << std::endl;
        return;
    }
    std::string bookName;
    std::cout<< "请输入要借阅的书籍名称：";
    std::cin >> bookName;
    Book bookToBorrow = inventory.findBook(bookName, "title");
    if (bookToBorrow.getTitle() != "NULL")
    {
        // 获取当前时间点
        std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
        // 将当前时间点转换为时间戳
        std::time_t timestamp = std::chrono::system_clock::to_time_t(now);
        // 将时间戳转换为本地时间
        std::tm *local_time = std::localtime(&timestamp);
        inventory.deleteBook(bookToBorrow);
        std::vector<std::string> status = {"已借阅", m_userName, std::asctime(local_time)};
        bookToBorrow = Book(bookToBorrow.getTitle(), bookToBorrow.getAuthor(), bookToBorrow.getISBN(), bookToBorrow.getPress(), bookToBorrow.getType(), status);

        // 将借阅信息写入库房文件
        inventory.addBook(bookToBorrow);
        std::ofstream outInventoryFile("inventory.csv");
        for (Book &book : inventory.getBooks())
        {
            outInventoryFile << book.getTitle() << ','
                    << book.getAuthor() << ','
                    << book.getISBN() << ','
                    << book.getPress() << ','
                    << book.getType() << ','
                    << book.getStatus()[0] << ','
                    << book.getStatus()[1] << ','
                    << book.getStatus()[2] << '\n';
        }
        std::ofstream outStudentUserFile("studentUser.csv");

        // 将借阅信息写入学生账户文件
        for (int index = 0; index < 3; index++)
        {
            if (m_reading[index] == "NULL")
            {
                m_reading[index] = bookToBorrow.getTitle();
                break;
            }
        }
        studentAccount.setStudentReading(m_userName, bookToBorrow.getTitle());  
        for (auto student : studentAccount.getUsers())
        {

            outStudentUserFile << student.getUserName() << ","
                               << student.getPassword() << ","
                               << student.getName() << ','
                               << student.getReading()[0] << ','
                               << student.getReading()[1] << ','
                               << student.getReading()[2] << ','
                               << '\n';
        }
        std::cout << "借阅成功!" << std::endl;
    }
    else
    {
        std::cout << "没有找到该书籍" << std::endl;
    }
}

void StudentUser::returnBook(StudentAccount &account, Inventory &inventory)
{
    if(m_reading[0] == "NULL" && m_reading[1] == "NULL" && m_reading[2] == "NULL" && m_reading[3] == "NULL")
    {
        std::cout << "当前未借阅任何书籍！" << std::endl;
        return;
    }
    std::cout << "请选择要归还的书籍名称：";
    int choice;
    for (int index = 0; index < 3; index++)
    {
        std::cout << index + 1 << '.' << m_reading[index] << std::endl;
    }
    std::cin >> choice;
    m_reading.erase(m_reading.begin() + choice - 1);
    Book bookToReturn = inventory.findBook(m_reading[choice - 1], "title");
    inventory.deleteBook(bookToReturn);
    bookToReturn.setStatus({"未借阅", "NULL", "NULL"});

    // 将归还信息写入库房文件
    inventory.addBook(bookToReturn);
    std::ofstream outFile("inventory.csv");
    for (Book &book : inventory.getBooks())
    {
        outFile << book.getTitle() << ','
                << book.getAuthor() << ','
                << book.getISBN() << ','
                << book.getPress() << ','
                << book.getType() << ','
                << "未借阅" << ','
                << "NULL" << ','
                << "NULL" << '\n';
    }

    // 将归还信息写入学生账户文件
    for (int index = 0; index < 3; index++)
    {
        if (m_reading[index] == bookToReturn.getTitle())
        {
            m_reading.erase(m_reading.begin() + index);
            m_reading.push_back("NULL");
            break;
        }
    }
    account.deleteStudentReading(m_userName, bookToReturn.getTitle());
    std::ofstream outStudentUserFile("studentUser.csv");
    for (auto student : account.getUsers())
    {

        outStudentUserFile << student.getUserName() << ","
                           << student.getPassword() << ","
                           << student.getName() << ','
                           << student.getReading()[0] << ','
                           << student.getReading()[1] << ','
                           << student.getReading()[2] << '\n';
    }
    std::cout << "归还成功!" << std::endl;
}

void StudentUser::storeStudentUser(StudentAccount& account)
{
    std::ofstream file("studentUser.csv", std::ios::app);

    // 检查文件是否成功打开
    if (!file.is_open())
    {
        std::cout << "用户目录出错，请联系管理员" << std::endl;
        return;
    }

    // 写入用户信息到CSV文件
    file    << m_userName << "," 
            << m_password << "," 
            << m_name << ','
            << m_reading[0] << ','
            << m_reading[1] << ','
            << m_reading[2] << '\n';

    account.addAccount(*this);
    // 关闭文件
    file.close();
}