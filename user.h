#pragma once
#include<string>
#include<unordered_map>

struct User
{
  public:
    User();
    User(std::string name, std::string userName, std::string password);
    void setName(std::string name);
    void setUserName(std::string userName);
    void setPassword(std::string password);
    std::string getName();
    std::string getUserName();
    std::string getPassword();

  protected:
    int id; //用户ID
    std::string m_name; //用户姓名
    std::string m_userName; //用户名
    std::string m_password; //用户密码
};
