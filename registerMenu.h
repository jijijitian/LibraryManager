#pragma once
#include"menu.h"

struct RegisterMenu:public Menu
{
    public:
        void printMenu();
        void printNameInput();  //打印输入姓名提示
        void printUserNameInput();  //打印输入用户名提示
        void printPasswordInput();  //打印输入密码提示
};