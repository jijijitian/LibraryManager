#pragma once
#include"studentAccount.h"
#include"studentUser.h"

struct Login
{
    public:
        bool checkAccount(StudentUser& user, StudentAccount& account);

};