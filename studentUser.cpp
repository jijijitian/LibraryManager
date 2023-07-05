#include"studentUser.h"
#include<fstream>
#include<sstream>
#include<iostream>

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
    file << m_name << "," << m_userName << "," << m_password << '\n';

    account.addAccount(m_userName, m_password);
    // 关闭文件
    file.close();
}