#include"register.h"
#include<iostream>

int Register::studentRegister(StudentAccount& account)  //学生注册实现
{
    int choice;
    std::string name, userName, password;
    char passwordConfirm;
    registerMenu.printMenu();
    std::cin >> choice;
    switch(choice)
    {
        case 1:
            system("clear");
            registerMenu.printNameInput();
            std::cin >> name;
            registerMenu.printUserNameInput();
            std::cin >> userName;
            registerMenu.printPasswordInput();
            while((passwordConfirm = getchar()) != '\n')
            {
                //如果用户输入的是退格符，则删除密码字符串中的最后一个字符
                if(passwordConfirm == '\b')
                {
                    if(password.empty() != true)
                    {
                        password.pop_back();
                        std::cout << "\b \b";
                    }
                }
                //如果用户输入的不是退格符，则将用户输入的字符加入密码字符串
                else
                {
                    password.push_back(passwordConfirm);
                    std::cout << "*";  //用星号代替密码
                }
            }
            studentUser.setName(name);
            studentUser.setUserName(userName);
            studentUser.setPassword(password);
            studentUser.storeStudentUser(studentAccount& account);
            std::cout << "注册成功！" << std::endl;
            break;
        case 2:
            break;
        default:
            //如果用户输入的不是1或2，则提示用户输入错误
            std::cout << "输入错误，请重新输入！" << std::endl;
            break;
    }
    return choice;
}