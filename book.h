#include<string>

struct Book
{
  public:
    void setTitle(std::string title); //设置书名
    void setAuthor(std::string author); //设置作者（默认不填）
    void setISBN(std::string ISBN); //设置ISBN（默认不填）
    void setPress(std::string press); //设置出版社（默认不填）
    std::string getTitle(); //获取书名
    std::string getAuthor();  //获取作者
    std::string getISBN();  //获取ISBN
    std::string getPress(); //获取出版社
  private:
    std::string m_title;  //书名
    std::string m_author; //作者
    std::string m_ISBN;
    std::string m_press;  //出版社
};
