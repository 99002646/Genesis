#ifndef __LIBRARY_H
#define __LIBRARY_H
#include<iostream>
#include<list>
#include<iterator>
#include<string>
#include<algorithm>
#include"book.h"

class Library
{
  int Id;
  std::basic_string<char> title;
  std::basic_string<char> author;
  std::basic_string<char> publisher;
  double price;
  int pages;
  std::list<Book, std::allocator<Book> > lib;
  
  public: 
  void addBook(int id,std::string title1,std::string title2,std::string title3,double cost, int pag);
  
  void removeBook(int id);
  
  void display();
  
  Book * findbook(int id);
  
  Book * findbook(std::basic_string<char> author_name);
  
  double averagePrice();
  
  int maxpages();
  
  int minpages();
  
  double average(std::basic_string<char> publisher_name);
  
  int booksrange(double rangemin, double rangemax);
  
  int countbooks(double cost);
  
  int countAll();
  
};

#endif
