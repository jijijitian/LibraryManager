#pragma once
#include"registerMenu.h"
#include"studentAccount.h"
#include"studentUser.h"

struct Register
{
    public:
        int studentRegister(StudentAccount& account);  //学生注册
        Register();

    private:
        RegisterMenu registerMenu;
        StudentUser studentUser;
};