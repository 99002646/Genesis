#ifndef __BOOK_H
#define __BOOK_H
#include<iostream>
#include<string>
class Book
{
  int Id;
  std::basic_string<char> title;
  std::basic_string<char> author;
  std::basic_string<char> publisher;
  double price;
  int pages;
  
  public: 
  inline Book()
  : Id{0}
  , title{std::basic_string<char>{std::basic_string<char>{std::basic_string<char>("", std::allocator<char>())}}}
  , author{std::basic_string<char>{std::basic_string<char>{std::basic_string<char>("", std::allocator<char>())}}}
  , publisher{std::basic_string<char>{std::basic_string<char>{std::basic_string<char>("", std::allocator<char>())}}}
  , price{0}
  , pages{0}
  {
  }
  
  inline Book(int id, std::basic_string<char> book_name, std::basic_string<char> author_name, std::basic_string<char> publisher_name, double cost, int number_pages)
  : Id{id}
  , title{std::basic_string<char>{std::basic_string<char>{std::basic_string<char>(std::basic_string<char>(std::basic_string<char>(std::basic_string<char>(book_name))))}}}
  , author{std::basic_string<char>{std::basic_string<char>{std::basic_string<char>(std::basic_string<char>(std::basic_string<char>(std::basic_string<char>(author_name))))}}}
  , publisher{std::basic_string<char>{std::basic_string<char>{std::basic_string<char>(std::basic_string<char>(std::basic_string<char>(std::basic_string<char>(publisher_name))))}}}
  , price{cost}
  , pages{number_pages}
  {
  }
  
  inline int getId()
  {
    return this->Id;
  }
  
  inline int getpages()
  {
    return this->pages;
  }
  
  inline int getprice()
  {
    return static_cast<int>(this->price);
  }
  
  inline std::basic_string<char> getauthor()
  {
    return std::basic_string<char>(std::basic_string<char>(std::basic_string<char>(this->author)));
  }
  
  inline std::basic_string<char> getpublisher()
  {
    return std::basic_string<char>(std::basic_string<char>(std::basic_string<char>(this->publisher)));
  }
  
  inline void display()
  {
    std::operator<<(std::operator<<(std::operator<<(std::operator<<(std::operator<<(std::operator<<(std::operator<<(std::operator<<(std::cout.operator<<(this->Id), ","), this->title), ","), this->author), ","), this->publisher), ",").operator<<(this->price), ",").operator<<(this->pages).operator<<(std::endl);
  }
};

#endif

