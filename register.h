#pragma once
#include"registerMenu.h"
#include"studentUser.h"

struct Register
{
    public:
        int studentRegister();  //学生注册
    private:
        RegisterMenu registerMenu;
        StudentUser studentUser;
};