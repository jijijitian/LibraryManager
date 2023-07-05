#include"library.h"
#include<iostream>

void Library::run()
{
    int choice;
    StudentAccount *account = new StudentAccount;
    while(true)
    {
        system("clear");
        LoginMenu *loginMenu = new LoginMenu;
        loginMenu->printMenu();
        std::cin >> choice;
        if(choice == 1)  // 学生登录
        {
            Login login;
            StudentUser *user = new StudentUser;
            system("clear");
            std::string userName, password;
            std::cout << "请输入用户名:";
            std::cin >> userName;
            user->setName(userName);
            std::cout << "请输入密码:";
            std::cin >> password;
            user->setPassword(password);
            while (!login.checkAccount(*user, *account))
            {
                std::cout << "用户名或密码错误，请重新输入！";
                std::cout << "请输入用户名:";
                std::cin >> userName;
                user->setName(userName);
                std::cout << "请输入密码:";
                std::cin >> password;
                user->setPassword(password);
            }
            if (login.checkAccount(*user, *account))
            {
                std::cout << "登录成功！";
                MainWindow *mainWindow = new MainWindow;
                system("clear");
                mainWindow->printMenu();
                int secondMenuChoice;
                std::cin >> secondMenuChoice;
                delete mainWindow;
                mainWindow = nullptr;
            }
            delete user;
            user = nullptr;
        }
        else if(choice == 2)  // 学生注册
        {
            Register* registerUser = new Register;
            registerUser->studentRegister(*account);
            delete registerUser;
            registerUser = nullptr;
            choice = 0;
        }
        else if(choice == 3)  // 管理员登录
        {
            std::cout << "管理员系统维护中！" << std::endl;
            exit(0);
        }
        else if(choice == 4)  // 退出
        {
            std::cout << "感谢使用图书管理系统" << std::endl;
            exit(0);
        }
        else
        {
            std::cout << "输入错误，请重新输入" << std::endl;
            std::cin >> choice;
        }
        delete loginMenu;
    }
    delete account;
}