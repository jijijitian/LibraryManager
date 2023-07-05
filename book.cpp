#include"book.h"

Book::Book(std::string title, std::string author, std::string ISBN, std::string press, std::string type)
{
  m_title = title;
  m_author = author;
  m_ISBN = ISBN;
  m_press = press;
  m_type = type;
  m_status[0] = "未借出";
}

Book::Book(std::string title, std::string author, std::string ISBN, std::string press, std::string type, std::vector<std::string> status)
{
  m_title = title;
  m_author = author;
  m_ISBN = ISBN;
  m_press = press;
  m_type = type;
  m_status = status;
}

void Book::setTitle(std::string title)
{
  m_title = title;
}

void Book::setAuthor(std::string author)
{
  m_author = author;
}

void Book::setISBN(std::string ISBN)
{
  m_ISBN = ISBN;
}

void Book::setPress(std::string press)
{
  m_press = press;
}

void Book::setType(std::string type)
{
  m_type = type;
}

void Book::setStatus(std::vector<std::string> status)
{
  m_status = status;
}

std::string Book::getTitle()
{
  return m_title;
}

std::string Book::getAuthor()
{
  return m_author;
}

std::string Book::getISBN()
{
  return m_ISBN;
}

std::string Book::getPress()
{
  return m_press;
}

std::string Book::getType()
{
  return m_type;
}

std::vector<std::string> Book::getStatus()
{
  return m_status;
}