#pragma once
#include<string>
#include<vector>

struct Book
{
  public:
    Book(std::string title, std::string author, std::string ISBN, std::string press, std::string type);  //构造函数
    Book(std::string title, std::string author, std::string ISBN, std::string press, std::string type, std::vector<std::string> m_status);  //构造函数
    void setTitle(std::string title);  //设置书名
    void setAuthor(std::string author);  //设置作者
    void setISBN(std::string ISBN);  //设置ISBN
    void setPress(std::string press);  //设置出版社
    void setType(std::string type);  //设置类型
    void setStatus(std::vector<std::string> status); //设置借阅状态
    std::string getTitle();  //获取书名
    std::string getAuthor();  //获取作者
    std::string getISBN();  //获取ISBN
    std::string getPress();  //获取出版社
    std::string getType();  //获取类型
    std::vector<std::string> getStatus();  //获取借阅状态(借阅状态，借阅人，借阅时间)
  private:
    std::string m_title;  //书名
    std::string m_author;  //作者
    std::string m_ISBN;
    std::string m_press;  //出版社
    std::string m_type;  //类型
    std::vector<std::string> m_status;  //借阅状态
};
