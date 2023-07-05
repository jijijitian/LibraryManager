#include"library.h"

void Library::run()
{
    StudentAccount *studentAccount = new StudentAccount;
    AdministratorAccount *administratorAccount = new AdministratorAccount;
    int firstMenuChoice;
    while(true)
    {
        system("clear");
        LoginMenu *loginMenu = new LoginMenu;
        loginMenu->printMenu();
        std::cin >> firstMenuChoice;
        if(firstMenuChoice == 1)  // 学生登录
        {
            StudentLogin* studentLogin = new StudentLogin;
            StudentUser *studentUser = new StudentUser(studentLogin->login(*studentAccount));
            while (studentUser->getName() == "NULL")
            {
                std::cout << "用户名或密码错误，请重新选择！" << std::endl;
                delete studentLogin;
                delete studentUser;
                studentLogin = nullptr;
                studentUser = nullptr;
                sleep(1);
                break;
            }
            while(true)
            {
                StudentMainWindow *studentMainWindow = new StudentMainWindow;
                int secondMenuChoice;
                system("clear");
                studentMainWindow->printMenu();
                std::cin >> secondMenuChoice;
                if(secondMenuChoice == 1)  // 借书
                {
                    
                }
                else if(secondMenuChoice == 2)  // 当前借阅
                {

                }
                else if(secondMenuChoice == 3)  // 还书
                {

                }
                else if(secondMenuChoice == 4)  // 退出登录
                {
                    delete studentMainWindow;
                    delete studentLogin;
                    delete studentUser;
                    delete studentAccount;
                    delete administratorAccount;
                    delete loginMenu;
                    studentMainWindow = nullptr;
                    studentLogin = nullptr;
                    studentUser = nullptr;
                    break;
                }
                else if(secondMenuChoice == 5)  // 退出程序
                {
                    std::cout << "感谢使用图书管理系统" << std::endl;
                    delete studentMainWindow;
                    delete studentLogin;
                    delete studentUser;
                    delete studentAccount;
                    delete administratorAccount;
                    delete loginMenu;
                    studentMainWindow = nullptr;
                    studentLogin = nullptr;
                    studentUser = nullptr;
                    studentAccount = nullptr;
                    administratorAccount = nullptr;
                    loginMenu = nullptr;
                    exit(0);
                }
                else
                {
                    std::cout << "输入错误，请重新输入" << std::endl;
                }
                delete studentMainWindow;
                studentMainWindow = nullptr;
            }
        }
        else if(firstMenuChoice == 2)  // 学生注册
        {
            Register* registerUser = new Register;
            registerUser->studentRegister(*studentAccount);
            delete registerUser;
            registerUser = nullptr;
            firstMenuChoice = 0;
        }
        else if(firstMenuChoice == 3)  // 管理员登录
        {
            AdministratorLogin *administratorLogin = new AdministratorLogin;
            AdministratorUser *administratorUser = new AdministratorUser(administratorLogin->login(*administratorAccount));
            while (administratorUser->getName() == "NULL")
            {
                std::cout << "用户名或密码错误，请重新选择！" << std::endl;
                delete administratorLogin;
                administratorLogin = nullptr;
                sleep(1);
                break;
            }
            while(true)
            {
                AdministratorMainWindow *administratorMainWindow = new AdministratorMainWindow;
                int secondMenuChoice;
                administratorMainWindow->printMenu();
                std::cin >> secondMenuChoice;
                if(secondMenuChoice == 1)  // 书籍列表
                {
                    
                }
                else if(secondMenuChoice == 2)  // 增加书籍
                {
                    
                }
                else if(secondMenuChoice == 3)  // 删除书籍
                {
                }
                else if(secondMenuChoice == 4)  // 更改书籍
                {
                }
                else if(secondMenuChoice == 5)  // 退出登录
                {
                    delete administratorMainWindow;
                    delete administratorLogin;
                    delete administratorUser;
                    administratorMainWindow = nullptr;
                    administratorLogin = nullptr;
                    administratorUser = nullptr;
                    break;
                }
                else if(secondMenuChoice == 6)  // 退出程序
                {
                    std::cout << "感谢使用图书管理系统" << std::endl;
                    delete administratorMainWindow;
                    delete administratorLogin;
                    delete administratorUser;
                    delete studentAccount;
                    delete administratorAccount;
                    delete loginMenu;
                    administratorMainWindow = nullptr;
                    administratorLogin = nullptr;
                    administratorUser = nullptr;
                    studentAccount = nullptr;
                    administratorAccount = nullptr;
                    loginMenu = nullptr;
                    break;
                    exit(0);
                }
                else
                {
                    std::cout << "输入错误，请重新输入" << std::endl;
                }
                delete administratorMainWindow;
                administratorMainWindow = nullptr;
            }
        }
        else if(firstMenuChoice == 4)  // 退出
        {
            std::cout << "感谢使用图书管理系统" << std::endl;
            delete studentAccount;
            delete administratorAccount;
            studentAccount = nullptr;
            administratorAccount = nullptr;
            exit(0);
        }
        else
        {
            std::cout << "输入错误，请重新输入" << std::endl;
            std::cin >> firstMenuChoice;
        }
        delete loginMenu;
        loginMenu = nullptr;
    }
}