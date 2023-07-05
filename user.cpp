#include"user.h"

User::User(std::string name, std::string userName, std::string password)
{
  m_name = name;
  m_userName = userName;
  m_password = password;
}

//设置账户姓名
void User::setName(std::string name)
{
  m_name = name;
}

//设置账户用户名
void User::setUserName(std::string userName)
{
  m_userName = userName;
}

//设置账户密码
void User::setPassword(std::string password)
{
  m_password = password;
}

//获取账户姓名
std::string User::getName()
{
  return m_name;
}

//获取账户用户名
std::string User::getUserName()
{
  return m_userName;
}

//获取账户密码
std::string User::getPassword()
{
  return m_password;
}