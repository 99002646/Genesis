#ifndef __BOOK_H
#define __BOOK_H

#include <string>
#include <iostream>

class Book {
  int m_id;
  std::string m_title;
  std::string m_author;
  std::string m_publisher;
  double m_price;
  int m_pages;

public:
  Book(int id, std::string title, std::string author, std::string publisher,
       double price, int pages)
      : m_id(id), m_title(title), m_author(author), m_publisher(publisher),
        m_price(price), m_pages(pages) {}
  void display() const {
      //print all data members
  }
  int getId() const { return m_id; }
  std::string getTitle() const { return m_title; }
  std::string getAuthor() const { return m_author; }
  std::string getPublisher() const { return m_publisher; }
  double getPrice() const { return m_price; }
  int getPages() const { return m_pages; }

  friend std::ostream& operator<< (std::ostream& rout, const Book& rb);
};
std::ostream& operator<< (std::ostream& rout, const Book& rb) {
  //print all members using rb
  return rout;
}
#endif