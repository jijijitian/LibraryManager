#include"book.h"

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
