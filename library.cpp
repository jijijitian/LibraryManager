#include"library.h"

void Library::run()
{
    StudentAccount *studentAccount = new StudentAccount;
    AdministratorAccount *administratorAccount = new AdministratorAccount;
    int choice;
    while(true)
    {
        system("clear");
        LoginMenu *loginMenu = new LoginMenu;
        loginMenu->printMenu();
        std::cin >> choice;
        if(choice == 1)  // 学生登录
        {
            StudentLogin* studentLogin = new StudentLogin;
            while(!studentLogin->login(*studentAccount))
            {
                std::cout << "用户名或密码错误，请重新输入！" << std::endl;
                sleep(1);
            }
            MainWindow *mainWindow = new MainWindow;
            mainWindow->printMenu();
            delete mainWindow;
            mainWindow= nullptr;
        }
        else if(choice == 2)  // 学生注册
        {
            Register* registerUser = new Register;
            registerUser->studentRegister(*studentAccount);
            delete registerUser;
            registerUser = nullptr;
            choice = 0;
        }
        else if(choice == 3)  // 管理员登录
        {
            AdministratorLogin *administratorLogin = new AdministratorLogin;
            while (!administratorLogin->login(*administratorAccount))
            {
                std::cout << "用户名或密码错误，请重新输入！" << std::endl;
                sleep(1);
            }
            MainWindow *mainWindow = new MainWindow;
            mainWindow->printMenu();
            delete mainWindow;
            mainWindow = nullptr;
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
        loginMenu = nullptr;
    }
    delete studentAccount;
    delete administratorAccount;
    studentAccount = nullptr;
    administratorAccount = nullptr;
}