#include"register.h"
#include<unistd.h>
#include<iostream>

int Register::studentRegister(StudentAccount& account)  //学生注册实现
{
    int choice;
    do
    {
        std::string name, userName, password;
        char passwordConfirm;
        system("clear");
        registerMenu.printMenu();
        std::cin >> choice;
        if(choice == 1)
        {
            system("clear");
            registerMenu.printNameInput();
            std::cin >> name;
            registerMenu.printUserNameInput();
            std::cin >> userName;
            registerMenu.printPasswordInput();
            std::cin >> password;
            /*while ((passwordConfirm = ()) != '\n')
            {
                // 如果用户输入的是退格符，则删除密码字符串中的最后一个字符
                if (passwordConfirm == '\b')
                {
                    if (!password.empty())
                    {
                        password.pop_back();
                        std::cout << "\b \b";
                        std::cout.flush(); // 保证立即输出到终端
                    }
                }
                // 如果用户输入的不是退格符，则将用户输入的字符加入密码字符串
                else
                {
                    password.push_back(passwordConfirm);
                    std::cout << "*";  // 用星号代替密码
                    std::cout.flush(); // 保证立即输出到终端
                }
            }*/
            studentUser.setName(name);
            studentUser.setUserName(userName);
            studentUser.setPassword(password);
            while(account.findAccount(userName))  //如果用户名已存在，则提示用户重新输入
            {
                system("clear");
                std::cout << "用户名已存在，请重新输入！" << std::endl;
                sleep(1);
                break;
            }
            if(!account.findAccount(userName))
            {
                studentUser.storeStudentUser(account);
                std::cout << "注册成功,即将返回主菜单！" << std::endl;
                sleep(2);
                break;  
            }
        }
        else if(choice == 2)
        {
            break;
        }
        else
        {
            //如果用户输入的不是1或2，则提示用户输入错误
            std::cout << "输入错误，请重新输入！" << std::endl;
            sleep(1);
        }
    } while (true);
    return choice;
}